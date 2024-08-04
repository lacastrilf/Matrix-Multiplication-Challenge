# Final Workshop

## Contents
- [Running](#running)
- [Methods or tools used](#Methods)
- [Screenshots of the code running](#authors)

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

5. Compile the `mmm_implementation.c` file inside the bin directory:
    ```
    gcc -o bin/mmm mmm_implementation.c
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

## Screenshots of the code running
- 
