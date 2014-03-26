#include "iostream"
#include "matrixsort.h"
#include "time.h"
#include "stdlib.h"

using namespace std;

int main()
{
    cout << "task 2.3 matrix sort" << endl;
    int N;
    int M;
    cout << "Enter size of matrix:" << endl;
    cin >> N >> M;
    srand(time(NULL));
    int **matrix = new int *[N];

    for (int i = 0; i < N; i++)
        matrix[i] = new int [M];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            matrix[i][j] = rand()%10;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    MatrixSort matrixSort;
    matrixSort.sortMatrix(matrix, N, M);

    cout << endl;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++)
        delete[] matrix[i];

    delete[] matrix;

    return 0;
}
