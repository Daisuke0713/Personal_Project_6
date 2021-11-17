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
	POINTER_TYPE
} valueType;

struct Value {
	valueType type;
	union {
		int i;
		double d;
		char *s;
		void *p;
		struct ConsCell {
			struct Value *car;
			struct Value *cdr;
		} c;
	};
};

typedef struct Value Value;

#endif /* VALUE_H_ */
