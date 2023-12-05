#include <iostream>
#include <omp.h>
#include "MatrixMultiplication.hpp"

// Function to multiply two matrices
void matrixMultiply(int **A, int **B, int **C, int rowsA, int colsA, int colsB) { // double ** signifies a pointer to a pointer to a variable (used for referencing 2D arrays)
    #pragma omp parallel for // applies parallelisation to outermost for loop
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            C[i][j] = 0; // initialises C matrix variable
            for (int k = 0; k < colsA; ++k) {
                C[i][j] += A[i][k] * B[k][j]; //'k' represents position in the row/column
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int **matrix, int rows, int cols) { // displays output of final matrix, as well as matrices to be multiplied.
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}