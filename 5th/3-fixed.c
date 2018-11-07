#include <stdio.h>
#include <stdlib.h>

typedef char elementtype;

struct node{
	elementtype element;
	struct node *next;
};

typedef struct node *list;

list cons(elementtype e,list l){
	struct node *first;
	first = (struct node *)malloc(sizeof(struct node));
	first->next = l;
	first->element = e;
	return first;
}

int length(list l){
	int len_list = 0;
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->next = l;
	temp->next = temp->next->next;

	while(temp->next != NULL){
		len_list++;
		temp->next = temp->next->next;
	}
	return len_list;
}

void print_int_list(list l){
	l = l->next;
	while(l != NULL){
		printf("[%c]",l->element);
		l = l->next;
	}
	printf("\n");
}

void insert(list l, elementtype e){
	struct node *content = (struct node *)malloc(sizeof(struct node));
	content->element = e;
	content->next = l->next;
	l->next = content;
}

struct node *

int main(){
	int i;
	char buf[128];
	char c;
	list l;
	list last;
	last = (struct node *)malloc(sizeof(struct node));
	last->next = last;
	l = last;
	fgets(buf,sizeof(buf),stdin);
	printf("here\n");
	for(i = 0;(c = buf[i])!= '\n';++i){
		last->next = cons(c,NULL);
		last = last->next;
	}
	print_int_list(l);
	while(fgets(buf,sizeof(buf),stdin) != NULL){
		sscanf(buf,"%d %c",&i,&c);
		//リストのi番目にcを挿入
		printf("%d番目に%cを挿入\n",i,c);
		//ここでリストの中身を出力
		print_int_list(l);
	}
	return 0;
}
