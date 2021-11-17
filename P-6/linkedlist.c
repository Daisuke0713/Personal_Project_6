#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "linkedlist.h"
#include "value.h"
#include "newmalloc.h"
/*
 * linkedlist.c
 *
 */

Value *make_null() {
	Value *null = new_malloc(sizeof(Value));
	null->type = NULL_TYPE;
	return null;
}

Value *cons(Value *new_car, Value *new_cdr) {
	Value *cons_cell = new_malloc(sizeof(Value));
	cons_cell->type = CONS_TYPE;
	cons_cell->c.car = new_car;
	cons_cell->c.cdr = new_cdr;
	return cons_cell;
}

Value *car(Value *list) {
	return list->c.car;
}

Value *cdr(Value *list) {
		return list->c.cdr;
}

bool is_null(Value *list) {
	return list->type == NULL_TYPE;
}

int size(Value *list) {
	int list_size = 0;
	while(!is_null(list)) {
		list = list->c.cdr;
		list_size += 1;
	}
	return list_size;
}

void display(Value *list) {
	printf("[");
	while(!is_null(list)) {
		switch(car(list)->type) {
			case INTEGER_TYPE:
				printf("%i", car(list)->i); break;
			case DOUBLE_TYPE:
				printf("%f", car(list)->d); break;
			case STRING_TYPE:
				printf("%s", car(list)->s); break;
			case CONS_TYPE:	break;
			case NULL_TYPE: break;
			case POINTER_TYPE: break;
		}

		if(cdr(list)->type != NULL_TYPE) {
			printf(", "); // separating comma
		}

		list = cdr(list);
	}
	printf("]\n");
}

Value *reverse(Value *list) {
	// Need memory allocation for every node of the new list
	Value *r_list = make_null();
	while(!is_null(list)) {
		Value *new_car = car(list);
		r_list = cons(new_car, r_list);
		list = cdr(list);
	}
	return r_list;
}

int main() {

}

