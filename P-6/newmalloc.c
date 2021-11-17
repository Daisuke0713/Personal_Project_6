#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "value.h"
#include "linkedlist.h"
/*
 * newmalloc.c
 */

#include "newmalloc.h"

Value *pointer_list;

void *new_malloc(size_t size) {

	if(pointer_list == NULL) {
		pointer_list = malloc(sizeof(Value));
		pointer_list->type = NULL_TYPE;
	}

	Value *new_cell = malloc(sizeof(Value));
	new_cell->type = CONS_TYPE;

	Value *new_car = malloc(sizeof(Value));
	new_car->type = POINTER_TYPE;
	new_car->p = malloc(size);

	new_cell->c.car = new_car;
	new_cell->c.cdr = pointer_list;
	pointer_list = new_cell;

	return new_car->p;
}

void new_malloc_free() {
	Value *next;
	while(!is_null(pointer_list)) {
		next = cdr(pointer_list);
		free(car(pointer_list)->p);
		free(car(pointer_list));
		free(pointer_list);

		pointer_list = next;
	}

	free(pointer_list);
	pointer_list = NULL;
}

void new_malloc_exit(int status) {
	new_malloc_free();
	exit(status);
}
