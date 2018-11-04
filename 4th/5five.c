#include <stdlib.h>
#include <stdio.h>

#define MAXSTACK 512

char buf[MAXSTACK];
char inputs[MAXSTACK];

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
		//printf("[%d]",p->contents[i]);		
	}
	//printf("\n");
}

elementtype pop(struct stack *p){
	int return_num = 0;
	if(p->top == -1){
		printf("Bad\n");
		exit(1);
		//exit(1);
	}else{
		return_num = p->contents[p->top];
		p->top--;
		//print_stacks(p);
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
	char comp_char;
	scanf("%s",inputs);
	initstack(&s);

	for(i = 0; i < MAXSTACK; i++){
		if(inputs[i] == '(' || inputs[i] == '{' || inputs[i] == '[' || inputs[i] == '<'){
			push(&s, inputs[i]);
		}else if(inputs[i] == ')' || inputs[i] == '}' || inputs[i] == ']' || inputs[i] == '>'){
			comp_char = pop(&s);
			if(comp_char == '('){
				if(inputs[i] != ')'){
					printf("Bad\n");
					return 0;
				}
			}else if(comp_char == '{'){
				if(inputs[i] != '}'){
					printf("Bad\n");
					return 0;
				}
			}else if(comp_char == '['){
				if(inputs[i] != ']'){
					printf("Bad\n");
					return 0;
				}
			}else{
				if(inputs[i] != '>'){
					printf("Bad\n");
					return 0;
				}
			}
		}
	}
	if(stackempty(&s)){
		printf("Good\n");
	}else{
		printf("Bad\n");
	}
	return 0;

}
