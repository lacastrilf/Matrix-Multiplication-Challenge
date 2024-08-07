#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define N 50
#define MIN_SIZE 2
#define MAX_SIZE 5000
#define MAX_NUM 100000

int main()
{
    srand((unsigned)time(NULL));
    int size = MIN_SIZE + (rand() % MAX_SIZE), iterator = 0;
    double time_spent = 0.0;

double matrixA[size][size] _attribute((aligned(64))), matrixB[size][size] __attribute((aligned(64))), matrixC[size][size] __attribute_((aligned(64)));

    while (iterator++ < N)
    {
        printf("Running iteration number: %d\n", iterator);

        clock_t begin_time = clock();

        // Start modifying here

// Using #pragma for the parallel inicialization of matrixA, matriXb and matrixC.
#pragma omp parallel for
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                matrixA[j][i] = 1 + ((double)rand() / RAND_MAX) * MAX_NUM;
                matrixB[i][j] = 1 + ((double)rand() / RAND_MAX) * MAX_NUM; // Change the order of initialization of matrixB
                matrixC[j][i] = 0;
            }
        }

// Change the multiplication order from jki to ijk.
// Divide the multiplication into four quadrants to execute each quadrant in parallel.
#pragma omp parallel for

        for (int i = 0; i < (size / 2); i++)
        {
            for (int j = 0; j < size / 2; j++)
            {
                for (int k = 0; k < size; k++)
                {
                    matrixC[i][j] += matrixA[i][k] * matrixB[j][k];
                }
            }
        }

#pragma omp parallel for

        for (int i = 0; i < size / 2; i++)
        {
            for (int j = (size / 2); j < size; j++)
            {
                for (int k = 0; k < size; k++)
                {
                    matrixC[i][j] += matrixA[i][k] * matrixB[j][k];
                }
            }
        }

#pragma omp parallel for

        for (int i = (size / 2); i < size; i++)
        {
            for (int j = 0; j < (size / 2); j++)
            {
                for (int k = 0; k < size; k++)
                {
                    matrixC[i][j] += matrixA[i][k] * matrixB[j][k];
                }
            }
        }

#pragma omp parallel for

        for (int i = (size / 2); i < size; i++)
        {
            for (int j = (size / 2); j < size; j++)
            {
                for (int k = 0; k < size; k++)
                {
                    matrixC[i][j] += matrixA[i][k] * matrixB[j][k];
                }
            }
        }

        // Stop modifying here

        clock_t end_time = clock();
        time_spent += (double)(end_time - begin_time) / CLOCKS_PER_SEC;
    }

    printf("Size of matrices: %d \n", size);
    printf("Running time: %f \n", (time_spent / N));

    return 0;
}
