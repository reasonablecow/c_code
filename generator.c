#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int IDX = 0;
int ARRAY[] = {5, 4, 3, 2, 1};
int ARRAY_COUNT = sizeof(ARRAY) / sizeof(ARRAY[0]);

int* next_int_ptr()
{
    if (IDX <= ARRAY_COUNT - 1) {
        return &ARRAY[IDX++];
    } else {
        return NULL;
    }
}

int main()
{
    for(int* int_ptr = next_int_ptr(); int_ptr; int_ptr = next_int_ptr()) {
        printf("%d, ", *int_ptr);
    }
    printf("\n");
}
