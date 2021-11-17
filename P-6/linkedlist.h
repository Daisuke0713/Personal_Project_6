#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include "value.h"
/*
 * linkedlist.h
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

// Create a NULL_TYPE value node
Value *make_null();

// Create a new CONS value node
Value *cons(Value *new_car, Value *newCdr);

// Returns a car
Value *car(Value *list);

// Returns a cdr
Value *cdr(Value *list);

// Checks if a null pointer
bool is_null(Value *value);

// Returns a size
int size(Value *value);

// Display a given linked list
void display(Value *list);

// Returns a reversed version of the given
// list that does not have the same reference
// as the original list
Value *reverse(Value *list);

// Free all the memory anyhow referred to by the given list
void cleanup(Value *list);

#endif /* LINKEDLIST_H_ */
