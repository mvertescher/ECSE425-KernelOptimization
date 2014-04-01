#include "ecse425projOPT.h"
#include "ecse425proj.h"


void matVecMult_opt(int N, const double *matA, const double *vecB, double *vecC) 
{
	/* Optimized implementation */ 

    // Assume square matrix of NxN and vector of Nx1
    int row, col;
    int row_offset = 0;
    double row_sum;
    
    // For each row of the output vector 
    for (row = 0; row < N; row++) {
        row_sum = 0;    // The output element   
        // Take the sum of the products of the row of matrix A and vector B
        for (col = 0; col < N; col++) 
            row_sum += matA[col + row_offset] * vecB[col];
        vecC[row] = row_sum;
        row_offset += N;	// The row offset 
    }

}

void matMult_opt(int N, const double *matA, const double *matB, double *matC) 
{
    /* Optimized implementation */ 

    int i,j,k;
    int row_offset_C = 0;
    int indexA = 0; // matA index
    int indexB = 0; // matB index

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < N; k++) {
                matC[k + row_offset_C] += matA[indexA] * matB[indexB];
                //matC[k+i*N] += matA[j+i*N] * matB[k+j*N];
                indexB += 1;
            }            
            indexA += 1;
        }
        indexB = 0;
        row_offset_C += N;
    }
        
    /* Old matMult_opt
    // Assume square matrix A of NxN and square matrix B of NxN
    int row, col, offsetA, offsetB, i, rowB;
    double sum;

    // For each row
    for (row = 0; row < N; row++) {
        // For each column 
        for (col = 0; col < N; col++) {
            sum = 0;
            offsetA = N * row; 
            offsetB = col; 
            rowB = 0;
            for (i = 0; i < N; i++) {
                sum += matA[offsetA + i] * matB[offsetB + rowB];
                rowB += N;
            }
            matC[offsetA + col] = sum;
        }
    }*/
	

}

