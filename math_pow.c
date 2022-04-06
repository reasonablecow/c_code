#include <stdlib.h>
#include <stdio.h>
#include <math.h> // -lm flag is needed for linking.

int main(int argc, char **argv)
{
    if (argc != 3) return EXIT_FAILURE;
    int base = atoi(argv[1]);
    int exponent = atoi(argv[2]);
    int result = (int) pow(base, exponent);
    printf("%d^%d = %d\n", base, exponent, result);
    return EXIT_SUCCESS;
}
