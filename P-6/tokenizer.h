/*
 * tokenizer.h
 */
#include "value.h"

#ifndef TOKENIZER_H_
#define TOKENIZER_H_

// Read all the input from stdin, and return a linked list of tokens
Value *tokenize();

// Display the contents
void displayTokens(Value *list);


#endif /* TOKENIZER_H_ */
