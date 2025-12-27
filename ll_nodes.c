#include "ll_nodes.h"
#include <stdio.h>

/** Prints out the value and memory address of an int variable, from it's pointer. */
void print_int(int *ptr) {
    printf("Address: %p Value: %d\n", ptr, *ptr);
}