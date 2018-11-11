#include <stdio.h>
#include <stdlib.h>

typedef int elementtype;

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
		printf("%d",l->element);
		l = l->next;
	}
	printf("\n");

}

void insert(list l, elementtype e){
	struct node *new = (struct node *)malloc(sizeof(struct node));
	struct node *content = (struct node *)malloc(sizeof(struct node));
	// printf("here@\n");
	content = l;
	new->element = e;
	new->next = content->next;
	content->next = new;
	// print_int_list(l);
}

int abs(int i){
	if(i < 0){
		return i * -1;
	}else{
		return i;
	}
}

//struct node *

int main(){
	int i,j;
	char buf[128];
	int c;
	list l;
	list last;
	list temp;
	last = (struct node *)malloc(sizeof(struct node));
	last->next = last;
	l = last;
	//fgets(buf,sizeof(buf),stdin);
	// printf("here\n");
	//for(i = 0;(c = buf[i])!= '\n';++i){
	//	last->next = cons(c,NULL);
	//	last = last->next;
	//}
	scanf("%d",&c);
	last->next = cons(c,NULL);
	last = last->next;
	//print_int_list(l);
	while(fgets(buf,sizeof(buf),stdin) != NULL){
		sscanf(buf,"%d",&i);
		printf("i = %d\n",i);
		last->next = cons(*i,NULL);
		last = last->next;
		//ここでリストの中身を出力
		//print_int_list(l);
	}
	print_int_list(l);
	return 0;

}
