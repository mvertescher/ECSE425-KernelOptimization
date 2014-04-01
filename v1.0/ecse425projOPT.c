#include "ecse425projOPT.h"
#include "ecse425proj.h"


void matVecMult_opt(int N, const double *matA, const double *vecB, double *vecC) 
{
    // Code in your optimized implementation here
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

void matMult_opt(int N, const double *matA, const double *matB, double *matC) 
{
    // Code in your optimized implementation here

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

