#include <iostream>
#include <omp.h>
#include "Functions/MatrixMultiplication.hpp"

// demonstration
int main() {
    // Matrix dimensions
    const int rowsA = 3;
    const int colsA = 3;
    const int rowsB = 3;
    const int colsB = 3;

    // Initialize matrices A, B, and C
    int **A = new int*[rowsA];
    int **B = new int*[rowsB];
    int **C = new int*[rowsA];
    
    for (int i = 0; i < rowsA; ++i) {
        A[i] = new int[colsA];
        B[i] = new int[colsB];
        C[i] = new int[colsB];
    }

    // Initialize matrix A with values
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            A[i][j] = i * colsA + j + 1;
        }
    }

    // Initialize matrix B with values
    for (int i = 0; i < rowsB; ++i) {
        for (int j = 0; j < colsB; ++j) {
            B[i][j] = i * colsB + j + 1;
        }
    }

    // Perform matrix multiplication
    matrixMultiply(A, B, C, rowsA, colsA, colsB);

    // Print matrices
    std::cout << "Matrix A:" << std::endl;
    printMatrix(A, rowsA, colsA);

    std::cout << "Matrix B:" << std::endl;
    printMatrix(B, rowsB, colsB);

    std::cout << "Matrix C (Result of A * B):" << std::endl;
    printMatrix(C, rowsA, colsB);

    // Clean up
    for (int i = 0; i < rowsA; ++i) {
        delete[] A[i];
        delete[] B[i];
        delete[] C[i];
    }
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
