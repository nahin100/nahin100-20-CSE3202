#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    void *ptr1, *ptr2;

    printf("Initial program break: %ld (%p)\n", (long)sbrk(0), (void *)sbrk(0));

    // Allocate 1024 bytes using sbrk
    ptr2 = sbrk(1024);
    if (ptr2 == (void *)-1) {
        printf("Error: sbrk failed\n");
        return 1;
    }
    printf("After sbrk(1024): %ld (%p)\n", (long)sbrk(0), (void *)sbrk(0));

    // Free manually allocated memory (not needed with sbrk, but included for symmetry)
    sbrk(-1024);
    printf("After sbrk(-1024): %ld (%p)\n", (long)sbrk(0), (void *)sbrk(0));

    // Allocate 1024 bytes using malloc
    ptr1 = malloc(1024);
    if (ptr1 == NULL) {
        printf("Error: malloc failed\n");
        return 1;
    }
    printf("After malloc(1024): %ld (%p)\n", (long)sbrk(0), (void *)sbrk(0));

    // Free allocated memory
    free(ptr1);
    printf("After free(ptr1): %ld (%p)\n", (long)sbrk(0), (void *)sbrk(0));

    return 0;
}
