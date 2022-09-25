#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[argc + 1])
{
    if (argc < 2) {
        return EXIT_FAILURE;
    }
    size_t length = strtoul(argv[1], NULL, 10);
    int var_array[length];
    for (size_t i = 0; i < length; i++) var_array[i] = 0;
    var_array[0] = 42;
    for (size_t i = 0; i < length; i++) {
        printf("%d%s", var_array[i], (i != length - 1)? ", ": "\n");
    }
    return EXIT_SUCCESS;
}
