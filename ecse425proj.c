#include "ecse425proj.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Specify the data layout format */
const DLayout dlayout = RowMaj;

void randInitialize(int sz, double *vPtr)
{
    int i;
    for (i = 0; i < sz; i++)
        vPtr[i] = drand48();
}

void displayVec(int sz, const double *vPtr)
{
    if(dlayout == RowMaj)
    {
        int i;
        printf("[");
        for (i = 0; i < sz; i++)
        {
            printf("%e",vPtr[i]);
            if(i < sz-1)
                printf(",");
            else
                printf("]");
        }
    }
}

void displayMat(int rows, int cols, const double *vPtr)
{
    if(dlayout == RowMaj)
    {
        int i;
        printf("[\n");
        for (i = 0; i < rows; i++) {
            displayVec(cols, &vPtr[i*rows]);
            printf("\n");
        }
        printf("]");
    }
}

void matMult(int N, const double *matA, const double *matB, double *matC)
{
    if(dlayout == RowMaj)
    {
        // Naive implementation 

        // Assume square matrix A of NxN and square matrix B of NxN
        int row,col,offsetA,offsetB,i;
        double sum;

        // For each row
        for (row = 0; row < N; row++) {
            // For each column 
            for (col = 0; col < N; col++) {
                sum = 0;
                offsetA = N * row; // Offset for A is the current row
                offsetB = col; // Offset for B is the current col
                // Sum vector A times vector B
                for (i = 0; i < N; i++) {
                    sum += matA[offsetA + i] * matB[offsetB + i * N];
                }
                matC[offsetA+col] = sum;
            }
        }
    }

}

void matVecMult(int N, const double *matA, const double *vecB, double *vecC)
{
    if(dlayout == RowMaj)
    {
        // Naive implementation 

        //vecC = matA x vecB        
        
        // Assume square matrix of NxN and vector of Nx1
        int row,col,row_offset;
        double row_sum;
        
        // For each row of the output vector 
        for (row = 0; row < N; row++) {
            row_sum = 0;    // The output element
            row_offset = N * row;   // The row offset 
            // Take the sum of the products of the row of matrix A and vector B
            for (col = 0; col < N; col++) 
                row_sum += matA[col+row_offset] * vecB[col];
            vecC[row] = row_sum;
        }
    }
}

double compareVecs(int N, const double *src, const double *ref)
{
    double ds = 0., ss = 0.;
    int i;
    for(i = 0; i < N; i++)
    {
        ds += (src[i] - ref[i]) * (src[i] - ref[i]);
        ss += ref[i] * ref[i];
    }
    ss = ds/ss;
    printf("Error SQUARED is: %e\n",ss);
    return ss;
}
