#include <stdlib.h>
#include <stdio.h>

#define MAXSTACK 128;	

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

void print_stacks(*p){
	int i;
	for(i = 0;i < p->top;i++){
		printf("[%d]",p->contents[i]);		
	}
	printf("\n");
}


int main(){
	struct stack s;
	int i;
	/* スタック s の初期化 */
	while(fgets(buf,sizeof(buf),stdin) != NULL) {
		if(buf[0]==’p’) {
		/* スタック s からのポップ操作 */
		} else {
		sscanf(buf,"%d", &i);
		/* スタック s への i のプッシュ操作 */
		}
	/* スタック s の中身を指定された形式で出力 */
	}
}
