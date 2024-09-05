#include <iostream>
#include <fstream>
#include <cuda.h>
#include <math.h>
#include "ImageWriter.h"

//First kernel for populating max and working buf
__global__
void firstKernel(int nRows, int nCols, int nSheets, int pt,
                            unsigned char* gpuArray,
                            unsigned char* maxBuf,
                            float* workingBuf){

    //Define a row and col for particular thread
    //These may not correspond to the voxel image's rows and cols
    int row = threadIdx.x;
    int col = blockIdx.x;

    int max = 0;
    float sum = 0.0;
    int offset;

    //Depending on projection type, iterate through image and for each pixel
    //on face, calculate max and sum of the direction facing either
    //towards or away
    if(pt == 1){
        for(int i = 0; i < nSheets; i++){
            offset = i*nRows*nCols + col*nRows + row;
            if(gpuArray[offset] > max){
                max = gpuArray[offset];
            }
            sum += gpuArray[offset] * (i+1.0)/nSheets;
        }
        maxBuf[row*nCols + col] = max;
        workingBuf[row*nCols + col] = sum;
    }else if(pt == 2){
        for(int i = nSheets - 1; i >= 0; i--){
            offset = i*nRows*nCols + col*nRows + row;
            if(gpuArray[offset] > max){
                max = gpuArray[offset];
            }
            sum += gpuArray[offset] * (i+1.0)/nSheets;
        }
        maxBuf[row*nCols + (nRows - col)] = max;
        workingBuf[row*nCols + (nRows - col)] = sum;
    }else if(pt == 3){
        for(int i = nCols - 1; i >= 0; i--){
            offset = row*nRows*nCols + i*nRows + col;
            if(gpuArray[offset] > max){
                max = gpuArray[offset];
            }
            sum += gpuArray[offset] * (i+1.0)/nCols;
        }
        maxBuf[col*nSheets + row] = max;
        workingBuf[col*nSheets + row] = sum;
    }else if(pt == 4){
        for(int i = 0; i < nCols; i++){
            offset = row*nRows*nCols + i*nRows + col;
            if(gpuArray[offset] > max){
                max = gpuArray[offset];
            }
            sum += gpuArray[offset] * (i+1.0)/nCols;
        }
        maxBuf[col*nSheets + (nSheets - row)] = max;
        workingBuf[col*nSheets + (nSheets - row)] = sum;
    }else if(pt == 5){
        for(int i = nRows - 1; i >= 0; i--){
            offset = col*nRows*nCols + row*nRows + i;
            if(gpuArray[offset] > max){
                max = gpuArray[offset];
            }
            sum += gpuArray[offset] * (i+1.0)/nRows;
        }
        maxBuf[col*nCols + row] = max;
        workingBuf[col*nCols + row] = sum;
    }else if(pt == 6){
        for(int i = 0; i < nRows; i++){
            offset = col*nRows*nCols + row*nRows + i;
            if(gpuArray[offset] > max){
                max = gpuArray[offset];
            }
            sum += gpuArray[offset] * (i+1.0)/nRows;
        }
        maxBuf[(nSheets - col)*nCols + row] = max;
        workingBuf[(nSheets - col)*nCols + row] = sum;
    }
}

//Kernel for taking working buf and weighing the values to make a new sum
__global__
void secondKernel(int nRows, int nCols, int nSheets, int pt, float* workingBuf, int size, unsigned char* sumBuf){
    //Define rows and cols again
    int row = threadIdx.x;
    int col = blockIdx.x;

    //Calculate the max sum in the workingBuf
    float maxWeightedSum = 0;
    for(int i = 0; i < size; i++){
        if(workingBuf[i] > maxWeightedSum){
            maxWeightedSum = workingBuf[i];
        }
    }

    //Depending on projection type, weigh the sum so that it is between 0 and 255
    if(pt == 1){
        sumBuf[row*nCols + col] = round(workingBuf[row*nCols + col]/maxWeightedSum*255.0);
    }else if(pt == 2){
        sumBuf[row*nCols + (nRows - col)] = round(workingBuf[row*nCols + (nRows - col)]/maxWeightedSum*255.0);
    }else if(pt == 3){
        sumBuf[col*nSheets + row] = round(workingBuf[col*nSheets + row]/maxWeightedSum*255.0);
    }else if(pt == 4){
        sumBuf[col*nSheets + (nSheets - row)] = round(workingBuf[col*nSheets + (nSheets - row)]/maxWeightedSum*255.0);
    }else if(pt == 5){
        sumBuf[col*nCols + row] = round(workingBuf[col*nCols + row]/maxWeightedSum*255.0);
    }else if(pt == 6){
        sumBuf[(nSheets - col)*nCols + row] = round(workingBuf[(nSheets - col)*nCols + row]/maxWeightedSum*255.0);
    }
}

void writeTheFile(std::string fName, int xres, int yres, const unsigned char* imageBytes, std::string type){
    //Append type to end of filename
    if(type == "max"){
        fName.append("MAX.png");
    }else if(type == "sum"){
        fName.append("SUM.png");
    }

	unsigned char* row = new unsigned char[3*xres];
	ImageWriter* w = ImageWriter::create(fName,xres,yres);
	int next = 0;
	for (int r=0 ; r<yres ; r++)
	{
		for (int c=0 ; c<3*xres ; c+=3)
		{
			row[c] = row[c+1] = row[c+2] = imageBytes[next++];
		}
		w->addScanLine(row);
	}
	w->closeImageFile();
	delete w;
	delete [] row;
}


int main(int argc, char* argv[]){

    //Get command line arguments
    int nRows = atoi(argv[1]);
    int nCols = atoi(argv[2]);
    int nSheets = atoi(argv[3]);
    int pt = atoi(argv[5]);
    std::string outFileName = argv[6];

    //Allocate host array
    unsigned char *array = new unsigned char[nRows * nCols * nSheets];

    //Open and read file, passing voxel data into host array
    std::ifstream file (argv[4], std::ifstream::binary);
    file.seekg (0, file.end);
    int length = file.tellg();
    file.seekg (0, file.beg);
    file.read(reinterpret_cast<char*>(array), length);
    file.close();

    //Copy the voxel data to the GPU
    size_t size = nRows * nCols * nSheets * sizeof(char);
    unsigned char* gpuArray;
    cudaMalloc((void**)&gpuArray, size);
    cudaMemcpy(gpuArray, array, size, cudaMemcpyHostToDevice);

    //Allocate three GPU buffers based on projection type
    if(pt == 1 || pt == 2){
        size = nRows * nCols * sizeof(char);
    }else if(pt == 3 || pt == 4){
        size = nRows * nSheets * sizeof(char);
    }else if(pt == 5 || pt == 6){
        size = nCols * nSheets * sizeof(char);
    }
    unsigned char* maxBuf;
    unsigned char* sumBuf;
    float* workingBuf;
    cudaMalloc((void**)&maxBuf, size);
    cudaMalloc((void**)&sumBuf, size);
    cudaMalloc((void**)&workingBuf, size);

    //CPU buffers
    unsigned char *h_buf;
    unsigned char *h_sumBuf;

    //Define threads per block, and blocks per grid, then launch kernels
    //Copy GPU buffers back to CPU
    //Write images
    if(pt == 1 || pt == 2){
        dim3 threadsPerBlock(nRows);
        dim3 blocksPerGrid(nCols);
        firstKernel<<<blocksPerGrid, threadsPerBlock>>>(nRows, nCols, nSheets, pt, gpuArray, maxBuf, workingBuf);
        secondKernel<<<blocksPerGrid, threadsPerBlock>>>(nRows, nCols, nSheets, pt, workingBuf, size, sumBuf);
        h_buf = new unsigned char[nRows*nCols];
        h_sumBuf = new unsigned char[nRows*nCols];
        cudaMemcpy(h_buf, maxBuf, size, cudaMemcpyDeviceToHost);
        cudaMemcpy(h_sumBuf, sumBuf, size, cudaMemcpyDeviceToHost);
        writeTheFile(outFileName, nCols, nRows, h_buf, "max");
        writeTheFile(outFileName, nCols, nRows, h_sumBuf, "sum");
    }else if(pt == 3 || pt == 4){
        dim3 threadsPerBlock(nSheets);
        dim3 blocksPerGrid(nRows);
        firstKernel<<<blocksPerGrid, threadsPerBlock>>>(nRows, nCols, nSheets, pt, gpuArray, maxBuf, workingBuf);
        secondKernel<<<blocksPerGrid, threadsPerBlock>>>(nRows, nCols, nSheets, pt, workingBuf, size, sumBuf);
        h_buf = new unsigned char[nRows*nSheets];
        h_sumBuf = new unsigned char[nRows*nSheets];
        cudaMemcpy(h_buf, maxBuf, size, cudaMemcpyDeviceToHost);
        cudaMemcpy(h_sumBuf, sumBuf, size, cudaMemcpyDeviceToHost);
        writeTheFile(outFileName, nSheets, nRows, h_buf, "max");
        writeTheFile(outFileName, nSheets, nRows, h_sumBuf, "sum");
    }else if(pt == 5 || pt == 6){
        dim3 threadsPerBlock(nCols);
        dim3 blocksPerGrid(nSheets);
        firstKernel<<<blocksPerGrid, threadsPerBlock>>>(nRows, nCols, nSheets, pt, gpuArray, maxBuf, workingBuf);
        secondKernel<<<blocksPerGrid, threadsPerBlock>>>(nRows, nCols, nSheets, pt, workingBuf, size, sumBuf);
        h_buf = new unsigned char[nSheets*nCols];
        h_sumBuf = new unsigned char[nSheets*nCols];
        cudaMemcpy(h_buf, maxBuf, size, cudaMemcpyDeviceToHost);
        cudaMemcpy(h_sumBuf, sumBuf, size, cudaMemcpyDeviceToHost);
        writeTheFile(outFileName, nCols, nSheets, h_buf, "max");
        writeTheFile(outFileName, nCols, nSheets, h_sumBuf, "sum");
    }

    //Delete all buffers
    delete array;
    delete h_buf;
    delete h_sumBuf;
    cudaFree(gpuArray);
    cudaFree(maxBuf);
    cudaFree(sumBuf);
    cudaFree(workingBuf);
    return 0;
}
