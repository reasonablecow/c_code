#include <stdio.h>
#include <stdlib.h>
#include <omp.h>    // Compile with -fopenmp flag.

#define MIN_PARALLEL_DEPTH 55

int fib(int n)
{
    int fib_n_1, fib_n_2;
    if (n <= 1)
        return n;

    // fib_n_1 must be shared, otherwise the variable would be trashed.
    #pragma omp task shared(fib_n_1) if(n > MIN_PARALLEL_DEPTH)
    {
        fib_n_1 = fib(n - 1);
    }

    // In case the if clause is not satisfied, the code runs sequentially.
    #pragma omp task shared(fib_n_2) if(n > MIN_PARALLEL_DEPTH)
    {
        fib_n_2 = fib(n - 2);
    }

    // Wait for both tasks to assign the shared variable values.
    #pragma omp taskwait
    {
        return fib_n_1 + fib_n_2;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2) return EXIT_FAILURE;
    int n = atoi(argv[1]);
    #pragma omp parallel
    {
        // The calculation must be started with a single thread,
        // otherwise every thread would calculate it on its own.
        #pragma omp single
        {
            printf("%d\n", fib(n));
        }
    }
    return EXIT_SUCCESS;
}
