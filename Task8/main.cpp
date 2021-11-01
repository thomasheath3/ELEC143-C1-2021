#include "../lib/uopmsb/uop_msb_2_0_0.h"
using namespace uop_msb_200;

// 4x4 Array
double M[4][4] = {
    {1.0, 2.0, 3.0, 4.0},
    {-3.0, -4.0, -5.0, -6.0},
    {10.0, 11.0, 12.0, 13.0},
    {-1.0, -2.0, -3.0, -4.0}
};

void display4x4Array(const double A[4][4])
{
    for (unsigned row=0; row<4; row++) {
        for (unsigned col=0; col<4; col++) {
            printf("%8.1f\t", A[row][col]);
        }
        printf("\n");
    }
}

// ***** WRITE YOUR FUNCTION HERE *****


// *****  END YOUR FUNCTION HERE  *****

int main()
{
    display4x4Array(M);

    // ***** MODIFY THE CODE BELOW HERE *****

    // 1. Create another 4x4 Array MT

    // 2. Write a nested loop to transpose M. Given Matrix A, the transpose A'[i][j]=A[j][i]
    //    For full marks, you must do this "in place" (without making another matrix) and as efficiently as possible

    // 3. Write a function to transpose a NxM array to a MxN array. Write code below to demonstrate it.
    //    Hint: I suggest you use pointers and make sure you understand how arrays are arranged in memory

    // ***** MODIFY THE CODE ABOVE HERE *****


    while (true) {
    }
}

