#include "matrixsort.h"
#include "iostream"

MatrixSort::MatrixSort()
{
}

void MatrixSort::sortMatrix(int *matrix[], int N, int M)
{
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M - i - 1; j++)
            if (matrix[0][j] > matrix[0][j + 1])
                for (int k = 0; k < N; k++)
                {
                    matrix[k][j] += matrix[k][j + 1];
                    matrix[k][j + 1] = matrix[k][j] - matrix[k][j + 1];
                    matrix[k][j] = matrix[k][j] - matrix[k][j + 1];
                }
}
