#include <stdlib.h>
#include <stdio.h>

#define MAXSTACK 128
#define N 11


char buf[N+2];
char canvas[N][N];
char inputs[MAXSTACK];

struct zahyo {
    int x, y;
};

struct stack{
	int top;
	struct zahyo contents[MAXSTACK];
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

struct zahyo pop(struct stack *p){
	struct zahyo return_num;
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

void push(struct stack *p, struct zahyo e){
	if(p->top == MAXSTACK-1){
		printf("Overflow\n");
		exit(1);
	}else{
		p->top++;
		p->contents[p->top] = e;
		print_stacks(p);
	}
}

void func(struct stack *p){

	struct zahyo zahyo;
	struct zahyo e;

	if(stackempty(p)){
		;
    }else{

		zahyo = pop(p);
		if(canvas[zahyo.x][zahyo.y+1] == ' '){
			printf("here\n");
			e.x = zahyo.x;
			e.y = zahyo.y + 1;
			push(p,e);
			canvas[zahyo.x][zahyo.y+1] = '.';
		}
		if(canvas[zahyo.x+1][zahyo.y] == ' '){
			e.x = zahyo.x + 1;
			e.y = zahyo.y;
			push(p,e);
			canvas[zahyo.x+1][zahyo.y] = '.';
		}
		if(canvas[zahyo.x][zahyo.y-1] == ' '){
			e.x = zahyo.x;
			e.y = zahyo.y - 1;
			push(p,e);
			canvas[zahyo.x][zahyo.y-1] = '.';
		}
		if(canvas[zahyo.x-1][zahyo.y] == ' '){
			e.x = zahyo.x - 1;
			e.y = zahyo.y;
			push(p,e);
			canvas[zahyo.x-1][zahyo.y] = '.';
		}
		// if(canvas[zahyo.x+1][zahyo.y+1] == ' '){
		// 	e.x = zahyo.x + 1;
		// 	e.y = zahyo.y + 1;
		// 	push(p,e);
		// 	canvas[zahyo.x+1][zahyo.y+1] = '.';
		// }
		// if(canvas[zahyo.x-1][zahyo.y+1] == ' '){
		// 	e.x = zahyo.x - 1;
		// 	e.y = zahyo.y + 1;
		// 	push(p,e);
		// 	canvas[zahyo.x-1][zahyo.y+1] = '.';
		// }
		// if(canvas[zahyo.x-1][zahyo.y-1] == ' '){
		// 	e.x = zahyo.x - 1;
		// 	e.y = zahyo.y - 1;
		// 	push(p,e);
		// 	canvas[zahyo.x-1][zahyo.y-1] = '.';
		// }
		// if(canvas[zahyo.x+1][zahyo.y-1] == ' '){
		// 	e.x = zahyo.x + 1;
		// 	e.y = zahyo.y - 1;
		// 	push(p,e);
		// 	canvas[zahyo.x+1][zahyo.y-1] = '.';
		// }
		func(p);
	}

}


int main(){
	struct stack s;
	int i,j;
	//char comp_char;
    struct zahyo zahyo;
    zahyo.x = N / 2;
    zahyo.y = N / 2;


    i = 0;
    initstack(&s);
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
            for (j = 0; j < N; ++j) {
                canvas[i][j] = buf[j];
            }
            ++i;
    }

	//ここを埋める↓

	push(&s, zahyo);
	func(&s);

	//ここを埋める↑

	//canvasの出力
    for (i = 0; i < N;++i){
        for (j = 0; j < N;++j){
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
    return 0;
}
