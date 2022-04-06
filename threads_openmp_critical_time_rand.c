#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <omp.h> // -fopenmp flag needs to be specified.

int main()
{
    time_t seconds = time(NULL);
    printf("%jd ~ seconds since 1970 ~ %s", seconds, asctime(gmtime(&seconds)));
    srand(seconds); // Seconds are used as a seed for the randomness generator.
    int number = rand();
    printf("number = %d\n\n", number);
    #pragma omp parallel
    {
        // When there is no clause about variable data-sharing attributes,
        // the variable (number) is initialized,
        // after the parallel block a value assigned by the last thread stays.
        #pragma omp critical
        {
            // Critical section is used to assure there is no interruption
            // between the variable assignment and its print.
            number = omp_get_thread_num();
            printf("%d {number = omp_get_thread_num();}\n", number);
        }
    }
    printf("\nnumber = %d\n", number);
    return EXIT_SUCCESS;
}
