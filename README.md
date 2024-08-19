# Final Workshop

## Contents
- [Running](#running)
- [Methods](#Methods)
- [Screenshots of the code running](#Screenshots)

## Running

1. Access APOLO in the corresponding schedule.

2. At a terminal, run the following command:
    ```
    git clone https://github.com/SCAR-EAFIT/Final-Workshop
    ```

3. Go to the directory where you cloned the project:
    ```
    cd Final-Workshop
    ```

4. Create a `bin` directory inside the root of the project:
    ```
    mkdir bin
    ```

5. Compile the `mmm_modificado.c` file inside the bin directory:
    ```
    gcc -o mmm_modificado.c -fopenmp -O2
    ```

6. Run the program:
    - In APOLO:
        ```
        sbatch job.sh
        ```

    - In you pc:
        ```
        ./bin/mmm
        ```


## Methods

Pointers and aligned Memory Allocation
  ```
    double(*matrixA)[size];
    double(*matrixB)[size];
    double(*matrixC)[size];

    matrixA = _aligned_malloc(size * size * sizeof(double), 64);
    matrixB = _aligned_malloc(size * size * sizeof(double), 64);
    matrixC = _aligned_malloc(size * size * sizeof(double), 64);
  ```
Using OpenMP for the parallelization of tasks such as matrix initialization and matrix multiplication in quadrants
```
    #pragma omp parallel for
 ```
Change the multiplication order from jki to ijk.
Divide the multiplication into four quadrants to execute each quadrant in parallel.

```
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
 ```

## Screenshots
-Initial Runnig Time:
    ![image](https://github.com/user-attachments/assets/d7b4ca97-2cf3-4b01-9097-9cb266f2deb2)

-Final Running Time:
    ![runnig time](https://github.com/user-attachments/assets/5cb5c825-d16a-44df-8c59-0e58a8301f02)


