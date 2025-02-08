#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char globBuf[65536];         /* Uninitialized data segment */
int primes[] = {2, 3, 5, 7}; /* Initialized data segment */

static int square(int x) { 
    int result; 
    result = x * x;
    return result; 
}

static void doCalc(int val) {
    printf("The square of %d is %d\n", val, square(val));
    if (val < 1000) {
        int t; 
        t = val * val * val;
        printf("The cube of %d is %d\n", val, t);
    }
}

int main(int argc, char *argv[]) {
    static int key = 9973;      /* Initialized data segment */
    static char mbuf[10240000]; /* Uninitialized data segment */
    char *p;                    /* Allocated in frame for main() */
    p = malloc(1024);           /* Points to memory in heap segment */

    printf("\nMemory addresses of variables and segments:\n");
    printf("---------------------------------------------------\n");
    printf("Address of function main() (Text): %lu (%p)\n", (unsigned long)main, (void *)main);
    printf("Address of function doCalc() (Text): %lu (%p)\n", (unsigned long)doCalc, (void *)doCalc);
    printf("Address of globBuf (BSS): %lu (%p)\n", (unsigned long)globBuf, (void *)globBuf);
    printf("Address of primes (Initialized Data): %lu (%p)\n", (unsigned long)primes, (void *)primes);
    printf("Address of key (Initialized Data): %lu (%p)\n", (unsigned long)&key, (void *)&key);
    printf("Address of mbuf (BSS): %lu (%p)\n", (unsigned long)mbuf, (void *)mbuf);
    printf("Address of malloc'd memory (Heap): %lu (%p)\n", (unsigned long)p, (void *)p);
    printf("Address of local variable p (Stack): %lu (%p)\n", (unsigned long)&p, (void *)&p);

    doCalc(key);

    free(p);
    return 0;
}
