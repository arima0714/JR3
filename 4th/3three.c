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
	(*p).top = 0;
}


int stackempty(struct stack *p){
	if((*p).top == 0){
		return 1;
	}else{
		return 0;
	}
}

elementtype pop(struct stack *p){

}

void push(struct stack *p, elementtype e){
	if(p->top == MAXSTACK){
		printf("Overflow\n");
	}else{
	
	}
}

void print_stacks(struct stack *p){
	int i;
	for(i = 0;i < p->top;i++){
		printf("[%d]",p->contents[i]);		
	}
	printf("\n");
}

int main(){
	struct stack s;
	int i;
	while(fgets(buf, sizeof(buf), stdin) != NULL){
		if(buf[0] == 'p'){
			
		}else{
			sscanf(buf,"%d",&i);
		}
	}
}
