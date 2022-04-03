#include <stdio.h>
#include <stdlib.h>

typedef struct VecInt {
    int len;
    int *arr;
} VecInt;
VecInt vec_int_new(int length)
{
    int *array = (int *) malloc(length * sizeof(int));
    return (VecInt) {.len=length, .arr=array};
}
void vec_int_del(VecInt vec)
{
    free(vec.arr);
}
void vec_int_print(VecInt *vec)
{
    for (int *elem = vec->arr; elem < (vec->arr + vec->len); elem++) {
        printf("%d", *elem);
        (elem != vec->arr + (vec->len - 1))? printf(", "): printf("\n");
    }
}

int main(int argc, char **argv)
{
    if (argc != 2) return 1;
    int length = atoi(argv[1]);
    VecInt vec = vec_int_new(length);
    for (int *elem = vec.arr; elem < (vec.arr + vec.len); elem++) {
        *elem = (elem == vec.arr)? vec.len: *(elem-1) - 1;
    }
    vec_int_print(&vec);
    vec_int_del(vec);
    return 0;
}
