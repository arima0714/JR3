#include <stdio.h>
#include <stdlib.h>

typedef int elementtype;

struct dlnode{
	elementtype element;
	struct dlnode *prev, *next;
};

typedef struct dlnode *list;

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
	struct dlnode *temp;
	temp = (struct dlnode *)malloc(sizeof(struct dlnode));
	temp = d;
	//printf("here!\n");
	temp = temp->next;
	
	while((temp->next != d->next)&&(temp->element != d->element)) {
		printf("[%d]",temp->element);
		temp = temp->next;
	}
	temp = temp->prev;
	while((temp->prev != d->prev)&&(temp->element != d->element)){
		printf("{%d}",temp->element);
		temp = temp->prev;
	}
	printf("\n");
}

void append_dllist(struct dlnode *d1, struct dlnode *d2){
	//struct dlnode *d1_temp;
	//struct dlnode *d2_temp;
	//d1_temp = (struct dlnode *)malloc(sizeof(struct dlnode)); 
	//d2_temp = (struct dlnode *)malloc(sizeof(struct dlnode)); 
	//d1_temp = d1;
	//d2_temp = d2;
	if((d2->prev == d2->next)){
	}else{
		d2->prev->next = d1;
		d1->prev->next = d2->next;
		d2->next->prev = d1->prev;
		d1->prev = d2->prev;
	}
	free(d2);
}

void dell_num(int num, struct dlnode *p){
	struct dlnode *temp;
	temp = (struct dlnode *)malloc(sizeof(struct dlnode));
	temp = p;
	temp = temp->next;
	while((temp->next != p->next) && (temp->element != p->element)){
		//printf("here!\n");
		if(((temp->element % 2)==num) || ((temp->element % 2)==-num)){
			//printf("here@\n");
			delete(temp);
		}
		temp = temp->next;
	}
}

int main(){
	char buf[128];
	int i;
	struct dlnode *d1;
	struct dlnode *d2;
	struct dlnode *d1_last;
        struct dlnode *d2_last;

	d1_last = (struct dlnode *)malloc(sizeof(struct dlnode));
	d1 = d1_last;
	
	d2_last = (struct dlnode *)malloc(sizeof(struct dlnode));
	d2 = d2_last;
	
	d2->next = d2_last;
	d2->prev = d2_last;
	d1->next = d1_last;
	d1->prev = d1_last;

	while(fgets(buf,sizeof(buf),stdin)!=NULL){
		sscanf(buf,"%d",&i);
		//printf("%d でinsert()が実行されます\n",i);
		insert(d1_last,i);//末尾にiを要素として挿入 
		insert(d2_last,i);//末尾にiを要素として挿入 
	}
	print_dllist(d1);
	print_dllist(d2);
	//d1は奇数要素,d2は偶数要素をそれぞれ削除する
	dell_num(1,d1);
	dell_num(0,d2);
	
	print_dllist(d1);
        print_dllist(d2);
	//d1の末尾にd2を連結
	append_dllist(d1,d2);
	print_dllist(d1);
	//print_dllist(d2);
	return 0;
}

