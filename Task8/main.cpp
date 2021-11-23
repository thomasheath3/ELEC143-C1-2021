#include "uop_msb.h"
using namespace uop_msb;

// 4x4 Array
double M[4][3] = {
    {1.0, 2.0, 3.0},
    {-3.0, -4.0, -5.0},
    {10.0, 11.0, 12.0},
    {-1.0, -2.0, -3.0}
};

double N[3][4] = {
    {1.0, 2.0, 3.0, 4.0},
    {-3.0, -4.0, -5.0, -6.0},
    {10.0, 11.0, 12.0, 13.0}
};

void displayArray(int rows, int cols, double *Array)
{
    for (unsigned row=0; row<rows; row++) {
        for (unsigned col=0; col<cols; col++) {
            printf("%8.1f\t", Array[(row*cols)+col]);
        }
        printf("\n");
    }
}

// ***** For (1) WRITE YOUR ARRAY Y HERE *****
// 25  27  29   31
//-41 -45 -49  -53
// 9  108 119  130
//-25 -27 -29  -31
double Y[4][4] = {  //creating a blank 4x4 matrix for Y
    {0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0},
    {0.0, 0.0, 0.0, 0.0},
};
// ***** For (3) WRITE YOUR FUNCTION HERE *****

// *****  END YOUR FUNCTION HERE  *****

int main()
{
    double* addressOfArray = (double*)M;    //Obtain base address of the array M
    displayArray(4,3,(double*)M);           //Display in terminal

    // ***** MODIFY THE CODE BELOW HERE *****
    // 1. Create another Array Y with the correct dimensions to hold the result of M*N (see comments above)

    // 2. Write a nested loop to perform a matrix multiplication M*N and store the result in Y
    for(int i = 0; i <= 3; i++){// loops 4 time, same number of rows as M
        for(int s = 0; s<=3; s++){ //loops 4 times to create each row for Y
            int value = 0;
            for(int x = 0; x <= 2; x++){ // loops 3 times as 3 additions have to be made
                value += M[i][x] * N[x][s]; // adding specific values from the two matrix together, the sum of 3 additions
            }
            
            Y[i][s] = value; // assignes the value of the additions to the correct row and column of Y 
            
        }

    }
    for(int z = 0; z<=3; z++){ // loops 4 times, number of rows for Y
        for(int j = 0; j<=3; j++){ // loops number of rows for Y
            printf("%f ", Y[z][j]); // this prints each row of Y and then a new line to present all values in matrix form
        }
        printf("\n");
    }
    // 3. Write a function to multiply two matrices together (see comments above). Include some text code to demonstrate it working

    // ***** MODIFY THE CODE ABOVE HERE *****


    while (true) {
    }
}

