#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char stack[] = "hello";
    char *heap = "hello";

    char *heap_string_malloc = malloc(7);
    heap_string_malloc = "hellop\n";

    printf("Address of stack[0]: %p\n", stack);
    printf("Address of heap[0]: %p\n", heap);
    printf("Address of heap_string_malloc[0]: %p\n", heap_string_malloc);

    free(heap_string_malloc);
}