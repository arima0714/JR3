#include <stdlib.h>
#include <stdio.h>
#define MAXQUEUE 512
#define N 10

char buf[N+2];
char heya[N][N];
int kyori[N][N];

struct zahyo {
	int x,y;
};

typedef struct zahyo elementtype;

struct queue{
	int front;
	int rear;
	elementtype contents[MAXQUEUE];
};

void initqueue(struct queue *p){
//構造体 queue のアドレスを受け取り，そのキューを空にする関数
	p->front = p->rear = 0;

}


int queueempty(struct queue *p){
//構造体 queue のアドレスを受け取り，そのキューが空なら 0，空でなければ 1 を返す関数． 
	if(p->front == p->rear){
		return 0;
	}else{
		return 1;
	}
}

elementtype getq(struct queue *p){
// 構造体 queue のアドレスを受け取り，そのキューから要素を取り出し，その要素を返す関数．
	if(queueempty(p) == 0){
		printf("Underflow\n");
		exit(1);
	}else{
		elementtype content = p->contents[p->front];
		p->front++;
		if(p->front == MAXQUEUE){
			p->front = 0;
		}
		//print_queue(p);
		return content;
	}
}

void putq(struct queue *p, elementtype e){
// 構造体 queue のアドレスを受け取り，そのキューに e を入れる関数．
		p->contents[p->rear] = e;
		p->rear++;
		if(p->rear == MAXQUEUE){
			p->rear = 0;
		}
		//print_queue(p);
}

int func(struct queue *p){
	struct zahyo one;
	struct zahyo two;
	if(queueempty(p)==0){
		return 0;
	}else{
		one = getq(p);
		// if(kyori[one.x][one.y] == -1 && heya[one.x][one.y] == ' '){
		// 	two.x = one.x;
		// 	two.y = one.y;
		// 	putq(p,two);
		// 	kyori[one.x][one.y] = kyori[one.x][one.y] + 1;
		// }
		if(kyori[one.x+1][one.y] == -1 && heya[one.x+1][one.y] != '*'){
			two.x = one.x+1;
			two.y = one.y;
			putq(p,two);
			kyori[one.x+1][one.y] = kyori[one.x][one.y] + 1;
			//printf("kyori[one.x+1][one.y] = %d\n",kyori[one.x+1][one.y]);
		}
		if(kyori[one.x][one.y+1] == -1 && heya[one.x][one.y+1] != '*'){
			two.x = one.x;
			two.y = one.y+1;
			putq(p,two);
			kyori[one.x][one.y+1] = kyori[one.x][one.y] + 1;
			//printf("kyori[one.x][one.y+1] = %d\n",kyori[one.x][one.y+1]);
		}
		if(kyori[one.x-1][one.y] == -1 && heya[one.x-1][one.y] != '*'){
			two.x = one.x-1;
			two.y = one.y;
			putq(p,two);
			kyori[one.x-1][one.y] = kyori[one.x][one.y] + 1;
			//printf("kyori[one.x-1][one.y] = %d\n",kyori[one.x-1][one.y]);
		}
		if(kyori[one.x][one.y-1] == -1 && heya[one.x][one.y-1] != '*'){
			two.x = one.x;
			two.y = one.y-1;
			putq(p,two);
			kyori[one.x][one.y-1] = kyori[one.x][one.y] + 1;
			//printf("kyori[one.x][one.y-1] = %d\n",kyori[one.x][one.y-1]);
		}
		func(p);
	}

}

int main(){
	struct queue s;
	int i,j;
	struct zahyo start, goal;
	struct zahyo e;
	initqueue(&s);
	for(i = 0;i < N;i++){
		for(j = 0; j < N;j++){
			kyori[i][j] = -1;
		}
	}

	i = 0;



	while(fgets(buf, sizeof(buf),stdin) != NULL){
		for(j = 0; j < N ; ++j){
			if(buf[j]=='S'){
				start.x = i;
				start.y = j;
				//printf("start\n");
				//buf[j] = ' ';
			}else if(buf[j] == 'G'){
				goal.x = i;
				goal.y = j;
				//printf("goal\n");
				//buf[j] = ' ';
			}
			heya[i][j] = buf[j];
		}
		++i;
	}

	// printf("before\n");
	// for(i = 0; i < N; i++){
	// 	for(j = 0; j < N;j++){
	// 		printf("%c",heya[i][j]);
	// 	}
	// 	printf("\n");
	// }

	kyori[start.x][start.y] = 0;
	e.x = start.x;
	e.y = start.y;
	putq(&s,e);

	func(&s);


	// printf("after\n");
	// for(i = 0; i < N; i++){
	// 	for(j = 0; j < N;j++){
	// 		printf("%d",kyori[i][j]);
	// 	}
	// 	printf("\n");
	// }

	printf("%d\n",kyori[goal.x][goal.y]);

	return 0;
}
