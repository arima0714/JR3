#include <stdlib.h>
#include <stdio.h>
#define MAXSTACK 128;	
typedef char elementtype;

struct stack{
	int top;
	elementtype contents[MAXSTACK];
};


