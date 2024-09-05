Hamza Hameed
EECS 690: Project 3

Readme

I have designed my program like this:
First the command line arguments are taken in
A host array is made for the entire voxel image
The file is read and its values inserted into the host array
A GPU array is allocated and the host array copies into this new one
Three more gpu buffers are made maxBuf, sumBuf and workingBuf
Depending on the orientation the threads per block will be given either nRows, nCols, or nSheets, likewise for blocks per grid
The first kernel is launched which will get the max values in a direction and insert them into the maxBuf, and the kernel will also get the weighted sums of all the values in a direction
The second kernel is launched which will find the maxWeightedSum in the entire workingBuf and use it to insert values into sumBuf which will be between 0 and 255
 Then both maxBuf and sumBuf are copied back into cpu buffers
These buffers are used to write the images
Lastly, all the buffers are deleted
