#include <stdio.h>
#include <stdlib.h>

void fu(int *value)
{
    *value = 5;
    printf("value %d\n", *value);
}

void gu(int **adr)
{
    *adr = (int*) malloc(1 * sizeof(int));
    **adr = 10;
    printf("**adr %d\n", **adr);
}

int main(int argc, char **argv)
{
    int value = 0;
    int * adr;

    fu(&value);
    printf("value %d\n", value);

    gu(&adr);
    printf("*adr %d\n", *adr);
    free(adr);
}
