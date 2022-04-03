#include <stdio.h>
#include <stdlib.h>

typedef struct Arr5 {
    int arr[5];
} Arr5;
void arr_5_print(Arr5 *array)
{
    for (int i = 0; i < 5; i++) {
        printf("%d, ", array->arr[i]);
    }
    printf("\n");
}

void modulo_3_and_print(Arr5 array)
{
    for (int i = 0; i < 5; i++) {
        array.arr[i] = array.arr[i] % 3;
    }
    arr_5_print(&array);
}

int main()
{
    Arr5 a = {.arr={5, 17, 21, 8, 9}};
    arr_5_print(&a);
    modulo_3_and_print(a);
    arr_5_print(&a);
    return 0;
}
