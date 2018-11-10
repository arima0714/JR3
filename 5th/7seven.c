#include <stdio.h>
#include <stdlib.h>

typedef int elementtype;

struct dlnode{
	elementtype element;
	struct dlnode *prev, *next;
};

typedef struct node *list;

void insert(struct dlnode *p, elementtype e){
	//pの指している接点のprevにeを含む接点を挿入する関数
	struct dlnode *content;
	content = (struct dlnode *)malloc(sizeof(struct dlnode));
	content->element = e;
	content->next = p;
	content->prev = p->prev;
	p->prev->next = content;
	p->prev = content;
}

void delete(struct dlnode *p){
	//pの指している接点のみを削除する関数(要free()によるメモリの開放)
	p->prev->next = p->next;
	p->next->prev = p->prev;
	
}

void print_dllist(struct dlnode *d){
	//
	struct dlnode *work_node;
	work_node = (struct dlnode *)malloc(sizeof(struct dlnode));
	work_node = d;
	printf("here!!\n");
	while(work_node->next != NULL){
		printf("[%d]",work_node->element);
		work_node = work_node->next;
	}
	while(work_node->prev != NULL){
		printf("{%d}",work_node->element);
		work_node = work_node->next;
	}
	
	printf("\n");
}

void append_dllist(struct dlnode *d1, struct dlnode *d2){
	//d1,d2の指している接点をダミーの接点とする2つの双方向リストを連結する関数
	;
}

int main(){
	char buf[128];
	int i;
	struct dlnode *d1,*d2;

	d1 = NULL;
	d2 = NULL;
	d1 = (struct dlnode *)malloc(sizeof(struct dlnode)); 
	d2 = (struct dlnode *)malloc(sizeof(struct dlnode)); 
	struct dlnode *d1_prev, *d1_next;
	struct dlnode *d2_prev, *d2_next;

	d1_prev = (struct dlnode *)malloc(sizeof(struct dlnode)); 
	d1_next = (struct dlnode *)malloc(sizeof(struct dlnode)); 
	d2_prev = (struct dlnode *)malloc(sizeof(struct dlnode));  
	d2_next = (struct dlnode *)malloc(sizeof(struct dlnode));

	d1->element = NULL;
	d2->element = NULL;

	//d1_prev = NULL;
        //d1_next = NULL;
        //d2_prev = NULL;
        //d2_next = NULL;

	d1_prev->next = d1;
	d1_next->prev = d1;
	d2_prev->next = d2;
	d2_next->prev = d2;

	d1->prev = d1_prev;
	d1->next = d1_next;
	d2->prev = d2_prev;
	d2->next = d2_next;                      
                 
	d1_prev->next = d1;
	d1_next->prev = d1;
	d2_prev->next = d2;
	d2_next->prev = d2;

	while(fgets(buf,sizeof(buf),stdin)!=NULL){
		sscanf(buf,"%d",&i);
		insert(d1,i);//末尾にiを要素として挿入 
		insert(d2,i);//末尾にiを要素として挿入 
	}
	printf("here$\n");
	print_dllist(d1);
	print_dllist(d2);
	
	//d1は奇数要素,d2は偶数要素をそれぞれ削除する
	print_dllist(d1);
	print_dllist(d2);
	//d1の末尾にd2を連結
	append_dllist(d1, d2);
	print_dllist(d1);
	return 0;
}

