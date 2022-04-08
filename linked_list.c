#include <stdlib.h>
#include <stdio.h>

typedef struct Link {
    int value;
    struct Link *prev;
} Link;
Link *link_new(int value, Link *prev)
{
    Link *link = (Link *) malloc(sizeof(Link));
    *link = (Link) {.value = value, .prev = prev};
    return link;
}
void link_free(Link *link)
{
    Link *for_free;
    while (link != NULL) {
        for_free = link;
        link = link->prev;
        free(for_free);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2) return EXIT_FAILURE;
    int number = atoi(argv[1]);
    Link *link = NULL;
    for (int i = 0; i < number; i++) {
        link = link_new(i, link);
    }
    for (Link *l_ptr = link; l_ptr != NULL; l_ptr = l_ptr->prev) {
        printf("l_ptr->value==%d\n", l_ptr->value);
    }
    link_free(link);
    return EXIT_SUCCESS;
}
