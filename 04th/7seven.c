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
	if(p->front > p->rear ){
		for(int i = p->front;i < MAXQUEUE;i++){
			printf("[%d]",p->contents[i]);
		}
		for(int i = 0;i< p->rear;i++){
			printf("[%d]",p->contents[i]);
		}
	}else{
		for(int i = p->front; i < p->rear; i++){
			printf("[%d]",p->contents[i]);
			//printf("Overflow\n");
			//exit(1);
		}
	}
	if(p->rear < p->front){
		//printf("[%d]",p->contents[127]);
	}
	printf("\n");
	//printf("p->front = %d, p->rear = %d\n",p->front , p->rear);
	if((p->front == 0 && p->rear == MAXQUEUE - 1) || (p->front == 1 && p->rear == 0)){
		printf("Overflow\n");
		exit(1);
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
		print_queue(p);
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
		print_queue(p);
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
