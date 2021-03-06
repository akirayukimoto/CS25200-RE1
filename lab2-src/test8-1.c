#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "MyMalloc.h"

#define ALLOCATIONS 1000
#define SEED 123456
#define MAX_SIZE 4096

/*
 * Allocate lots of pseudo-random sized blocks of memory, write to them, then free them all
 */

int main(int argc, char **argv) {
  // Set the random seed

  srand(SEED);
  char * ptrs[ALLOCATIONS];
  int i;
  for (i = 0; i < ALLOCATIONS; i++) {

    // Get a random size, no greater than MAX_SIZE

    size_t alloc_size = rand() % MAX_SIZE;

    // Allocate some memory and store in the pointer array

    ptrs[i] = (char *) malloc(alloc_size * sizeof(char));

    // Write to every part of allocated memory.

    memset(ptrs[i], 255, alloc_size);
  }

  print_list();

  // Free all the allocated memory

  for (i = 0; i<ALLOCATIONS; i++) {
    free(ptrs[i]);
  }

  print_list();
} /* main() */
