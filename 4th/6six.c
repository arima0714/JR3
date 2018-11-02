#include <stdlib.h>
#include <stdio.h>
#define MAXQUEUE 128 

char buf[MAXQUEUE];
typedef int elementtype;

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

void print_queue(struct queue *p){
	for(int i = p->front; i < p->rear; i++){
		printf("[%d]",p->contents[i]);
	}
	printf("\n");
}

elementtype getq(struct queue *p){
// 構造体 queue のアドレスを受け取り，そのキューから要素を取り出し，その要素を返す関数．
	if(queueempty(p) == 0){
		printf("Underflow\n");
		exit(1);
	}else{
		elementtype content = p->contents[p->front];
		p->front++;
		print_queue(p);
		return content;
	}
}

void putq(struct queue *p, elementtype e){
// 構造体 queue のアドレスを受け取り，そのキューに e を入れる関数．
	if(p->rear == MAXQUEUE){
		printf("Sorry\n");
		exit(1);
	}else{
		p->contents[p->rear] = e;
		p->rear++;
		print_queue(p);
	}	
}

int main(){
	struct queue s;
	int i;
	initqueue(&s);
	while(fgets(buf, sizeof(buf), stdin) != NULL){
		if(buf[0] == 'g'){
			getq(&s);
		}else{
			sscanf(buf,"%d",&i);
			putq(&s, i);
		}
	}
}
