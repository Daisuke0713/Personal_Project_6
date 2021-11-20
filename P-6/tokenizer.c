#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "value.h"
#include "newmalloc.h"
#include "linkedlist.h"
/*
 * tokenizer.c
 */

#include "tokenizer.h"

// one digit
bool is_digit(char c) {
	if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
			|| c == '6' || c == '7' || c == '8' || c == '9') {
		return true;
	}
	return false;
}

// a sequence of digits
bool are_digits(char *str) {
	for(int i = 0; i < strlen(str); i++) {
		if(!is_digit(str[i])) {
			return false;
		}
	}
	return true;
}

// a decimal
bool is_decimal(char *str) {
	if(str[0] == '+' || str[1] == '-') {
		str = str+1;
	}

	for(int i = 0; i < strlen(str); i++) {
		if(str[i] == '.') {
			return are_digits(str[i+1]);
		}
	}
	return false;
}

// a integer
bool is_integer(char *str) {
	if(str[0] == '+' || str[0] == '-') {
		return are_digits(str+1);
	}
	return are_digits(str);
}

// a letter
bool is_letter(char c) {
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";
	char *ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if(strchr(alphabet, c) == NULL && strchr(ALPHABET, c) == NULL) {
		return false;
	}
	return true;
}

// an initial
bool is_initial(char c) {
	char *symbols = "!$%&*/:<>=?~_^";
	if(strchr(symbols, c) != NULL) {
		return true;
	}
	return is_letter(c);
}

bool is_boolean(char *str) {
	if(strlen(str) == 2) {
		return strcmp(str, "#t", 2) || strcmp(str, "#f", 2);
	}
	return false;
}

bool is_sub




