#include <stdlib.h>
#include "value.h"
/*
 * newmalloc.h
 */

#ifndef NEWMALLOC_H_
#define NEWMALLOC_H_

// Store all the pointers as a list
void *new_malloc(size_t size);

// Free all the pointers allocated by new_malloc
void new_malloc_free();

// Exits a program with a status
void new_malloc_exit(int status);

#endif /* NEWMALLOC_H_ */
