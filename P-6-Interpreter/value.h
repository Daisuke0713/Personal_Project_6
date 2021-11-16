/*
 * value.h
 */

#ifndef VALUE_
#define VALUE_

// With typedef, we can omit valueType when defining
typedef enum {
	INTEGER_TYPE,
	DOUBLE_TYPE,
	STRING_TYPE,
	CONS_TYPE,
	NULL_TYPE,
} valueType;

struct Value {
	valueType type;
	union {
		int i;
		double d;
		char *s;
		struct ConsCell {
			struct Value *car;
			struct Value *cdr;
		} c;
	};
};

typedef struct Value Value;

#endif /* VALUE_H_ */
