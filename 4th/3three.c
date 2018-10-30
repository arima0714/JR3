#include <stdlib.h>
#include <stdio.h>

#define MAXSTACK 128

char buf[MAXSTACK];

typedef int elementtype;

struct stack{
	int top;
	elementtype contents[MAXSTACK];
};

void initstack(struct stack *p){
	(*p).top = -1;
}


int stackempty(struct stack *p){
	if((*p).top == -1){
		return 1;
	}else{
		return 0;
	}
}

void print_stacks(struct stack *p){
	int i;
	for(i = 0;i <= p->top;i++){
		printf("[%d]",p->contents[i]);		
	}
	printf("\n");
}

elementtype pop(struct stack *p){
	int return_num = 0;
	if(p->top == -1){
		printf("Underflow\n");
		exit(1);
	}else{
		return_num = p->contents[p->top];
		p->top--;
		print_stacks(p);
		return return_num;
	}
}

void push(struct stack *p, elementtype e){
	if(p->top == MAXSTACK-1){
		printf("Overflow\n");
		exit(1);
	}else{
		p->top++;
		p->contents[p->top] = e;
		print_stacks(p);
	}
}


int main(){
	struct stack s;
	int i;
	initstack(&s);
	while(fgets(buf, sizeof(buf), stdin) != NULL){
		if(buf[0] == 'p'){
			pop(&s);
		}else{
			sscanf(buf,"%d",&i);
			push(&s, i);
		}
	}
}
