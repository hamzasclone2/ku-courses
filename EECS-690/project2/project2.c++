//project2.c++

// Hamza Hameed
// EECS690

#include "ImageReader.h"
#include <mpi.h>
#include <cmath>

//gets the red, green, or blue value for each pixel in the image
//returns array of these values for specified color
int* createRGBArray(const cryph::Packed3DArray<unsigned char>* pa, int height,
					int width, std::string color){
	int colorSize = 256;
	int* rgb = new int[colorSize];
	//initializes array
	for(int i = 0; i < colorSize; i++){
		rgb[i] = 0;
	}
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			if(color == "red"){
				rgb[pa->getDataElement(i,j,0)]++;
			}else if(color == "green"){
				rgb[pa->getDataElement(i,j,1)]++;
			}else if(color == "blue"){
				rgb[pa->getDataElement(i,j,2)]++;
			}
		}
	}
	return rgb;
}

//takes each histogram and converts it into percentages
//returns new array with percentages
float* calculatePercentages(int* array){
	int total = 0;
	int size = 256;
	float f;
	float* fa = new float[size];
	for(int i = 0; i < size; i++){
		total += array[i];
	}
	for(int i = 0; i < size; i++){
		f = (float)array[i] / (float)total;
		fa[i] = f;
	}
	return fa;
}

//receives data from rank 0
//calls calculatePercentages()
float* receive(MPI_Status status, std::string color){
	int size = 256;
	int* buf = new int[size];

	if(color == "red"){
		MPI_Recv(buf, size, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
	}else if(color == "green"){
		MPI_Recv(buf, size, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
	}else if(color == "blue"){
		MPI_Recv(buf, size, MPI_INT, 0, 2, MPI_COMM_WORLD, &status);
	}

	float* f = calculatePercentages(buf);
	return f;
}

//compares two histograms and returns a total of their differences
float compare(float* arr, float* arr2){
	int size = 256;
	float* difs = new float[size];
	float total = 0.0;
	for(int i = 0; i < size; i++){
		difs[i] = std::abs(arr[i] - arr2[i]);
		total += difs[i];
	}
	return total;
}

//the main work assignment for each rank
//returns the image index that each rank is most similar to
int work(int commSize, MPI_Status status, int rank){
	int size = 256;

	//percentage arrays
	float* redf = receive(status, "red");
	float* greenf = receive(status, "green");
	float* bluef = receive(status, "blue");

	//arrays that will receive the info from all-gather
	float* agRed = new float[commSize * size];
	float* agGreen = new float[commSize * size];
	float* agBlue = new float[commSize * size];

	//send the ranks percentage arrays to all the other processes
	MPI_Allgather(redf, size, MPI_FLOAT, agRed, size, MPI_FLOAT, MPI_COMM_WORLD);
	MPI_Allgather(greenf, size, MPI_FLOAT, agGreen, size, MPI_FLOAT, MPI_COMM_WORLD);
	MPI_Allgather(bluef, size, MPI_FLOAT, agBlue, size, MPI_FLOAT, MPI_COMM_WORLD);

	//totals of the differences of the color values
	float* redTotal = new float[commSize];
	float* greenTotal = new float[commSize];
	float* blueTotal = new float[commSize];

	//two arrays for each color for comparisons
	float* arrRed = new float[size];
	float* arr2Red = new float[size];
	float* arrGreen = new float[size];
	float* arr2Green = new float[size];
	float* arrBlue = new float[size];
	float* arr2Blue = new float[size];

	int min;
	int minIdx;
	float* total = new float[commSize];

	//each rank uses the all-gather arrays to compare its values
	//to the rest of the processes values
	//and get the differences from each process
	for(int i = 0; i < commSize; i++){
		if(i != rank){
			for(int x = 0; x < size; x++){
				arrRed[x] = agRed[commSize * rank];
				arrGreen[x] = agGreen[commSize * rank];
				arrBlue[x] = agBlue[commSize * rank];

				arr2Red[x] = agRed[commSize * i];
				arr2Green[x] = agGreen[commSize * i];
				arr2Blue[x] = agBlue[commSize * i];
			}
			redTotal[i] = compare(arrRed, arr2Red);
			greenTotal[i] = compare(arrGreen, arr2Green);
			blueTotal[i] = compare(arrBlue, arr2Blue);
			total[i] = redTotal[i] + greenTotal[i] + blueTotal[i];
		}else{
			total[i] = 999;
		}
	}

	//finds the minimum value from all the totals
	//so the smallest one is the one that the rank is most similar to
	min = total[0];
	minIdx = 0;
	for(int i = 0; i < commSize; i++){
		if(total[i] < min){
			min = total[i];
			minIdx = i;
		}
	}
	return minIdx;
}

//main program
int main(int argc, char* argv[]){
	//if no images are inputted
	if (argc < 2){
		std::cerr << "Usage: " << argv[0] << " imageFileName\n";
	}else{
		int size = 256;

		MPI_Init(&argc, &argv);
		int rank, commSize;
		MPI_Comm_rank(MPI_COMM_WORLD, &rank);
		MPI_Comm_size(MPI_COMM_WORLD, &commSize);
		MPI_Request request;
		MPI_Status status;

		//if -n # does not match the number of images given
		if(commSize != argc - 1){
			if(rank == 0){
				std::cerr << "\nError! Not enough arguments or incorrect n\n"
						  << "Example Usage: mpirun -n 3 ./projec2 img1.png img2.jpg img3.png\n\n";
			}
			MPI_Finalize();
			return 0;
		}

		ImageReader* ir;
		cryph::Packed3DArray<unsigned char>* pa;
		if(rank == 0){
			//get rgb values of each image and send them out to each process
			int *red, *green, *blue;
			int height, width;
			for(int i = 1; i < argc; i++){
				ir = ImageReader::create(argv[i]);
				pa = ir -> getInternalPacked3DArrayImage();

				height = pa -> getDim1();
				width = pa -> getDim2();

				red = createRGBArray(pa, height, width, "red");
				green = createRGBArray(pa, height, width, "green");
				blue = createRGBArray(pa, height, width, "blue");
				MPI_Isend(red, size, MPI_INT, i-1, 0, MPI_COMM_WORLD, &request);
				MPI_Isend(green, size, MPI_INT, i-1, 1, MPI_COMM_WORLD, &request);
				MPI_Isend(blue, size, MPI_INT, i-1, 2, MPI_COMM_WORLD, &request);
			}

			//do the main work of the program
			//val = index of image that it is most similar to
			int val = work(commSize, status, rank);
			int* fin = new int[commSize];

			//send and gather values from all processes into one array
			MPI_Gather(&val, 1, MPI_INT, fin, 1, MPI_INT, 0, MPI_COMM_WORLD);
			//print out what image each rank is closest to
			for(int i = 0; i < commSize; i++){
				std::cout << "Rank " << i << " is most similar to Rank " << fin[i] << ".\n";
			}
		}else{
			int val = work(commSize, status, rank);
			//send values to rank 0
			MPI_Gather(&val, 1, MPI_INT, NULL, 0, MPI_INT, 0, MPI_COMM_WORLD);
		}
	}
	//end of program
	MPI_Finalize();
	return 0;
}
