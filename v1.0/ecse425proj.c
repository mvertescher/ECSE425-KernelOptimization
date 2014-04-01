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
        // Code in your naive implementation here

        // Assume square matrix A of NxN and square matrix B of NxN
        int row,col,offsetA,offsetB,i;
        double sum;

        for (row = 0; row < N; row++) {
            for (col = 0; col < N; col++) {
                sum = 0;
                offsetA = N * row; 
                offsetB = col; 
                for (i = 0; i < N; i++) {
                    sum += matA[offsetA+i] * matB[offsetB+i*N];
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
        // Code in your naive implementation here
        //vecC = matA x vecB
        
        // Assume square matrix of NxN and vector of Nx1
        int row,col,row_offset;
        double row_sum;
        for (row = 0; row < N; row++) {
            row_sum = 0; 
            row_offset = N * row;
            for (col = 0; col < N; col++) {
                row_sum += matA[col+row_offset] * vecB[col];
            }  
            vecC[row] = row_sum;
        }

    }
}

void verifyMatMult(int N, const double *matA, const double *matB, const double *matC)
{
    double *ref;
    ref = (double *) malloc(N*N * sizeof(double));
    matMult(N,matA,matB,ref); // Use TA's reference implementation
    compareVecs(N,matC,ref);
    free(ref);
}

void verifyMatVecMult(int N, const double *matA, const double *vecB, const double *vecC)
{

    double *ref;
    ref = (double *) malloc(N * sizeof(double));
    matVecMult(N,matA,vecB,ref); // Use TA's reference implementation
    compareVecs(N,vecC,ref);
    free(ref);
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
