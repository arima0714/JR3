#include <stdio.h>
#include <stdlib.h>

typedef int elementtype;

struct node{
	elementtype element;
	struct node *next;
};

typedef struct node *list;

list cons(elementtype e,list l,list max){
	struct node *temp_one;
	temp_one = (struct node *)malloc(sizeof(struct node));
	struct node *temp_two;
	temp_two = (struct node *)malloc(sizeof(struct node));
	struct node *content;
	content = (struct node *)malloc(sizeof(struct node));
	content->element = e;
	content->next = NULL;
	if(max->element <= content->element){
		max->next = content->next;
		max->element = content->element;
	}
	//temp->next = l;
	//temp->element = e;
	temp_one = l;
	temp_two = temp_one;
	while(temp_one->next != NULL){
		temp_one = temp_one->next;
	}
	temp_one->next = content;
	return temp_two;
}

int length(list l){
	int len_list = 0;
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->next = l;

	while(temp->next != NULL){
		len_list++;
		temp->next = temp->next->next;
	}
	return len_list;
}

void print_int_list(list l){
	while(l != NULL){
		printf("[%d]",l->element);
		l = l->next;
	}
	printf("\n");
}
list func(list max, list l){
	struct node *temp_one;
	struct node *temp_two;
	struct node *temp_three;

	printf("here!\n");

	temp_one = (struct node *)malloc(sizeof(struct node));
	temp_two = (struct node *)malloc(sizeof(struct node));
	temp_three = (struct node *)malloc(sizeof(struct node));
	
	temp_one = l;
	while(temp_one->next != NULL){
		temp_one = temp_one->next;
	}
	temp_one->next = l;

	while((l->next != max->next)&&(l->element != max->element)){
		l = l->next;
	}

	//return l;

	printf("[%d]",l->element);
	l = l->next;

	while((l->next != max->next)&&(l->element != max->element)){
		printf("[%d]",l->element);
		l = l->next;
	}
	printf("\n");
	exit(1);
}


int main(){
	int i;
	char buf[128];
	struct node *l;
	l = (struct node *)malloc(sizeof(struct node));
	struct node *max;
	max = (struct node*)malloc(sizeof(struct node));
	max->element = -10000;
	while(fgets(buf,sizeof(buf),stdin) != NULL){
		sscanf(buf, "%d", &i);
		cons(i,l,max);
	}
	l = l->next;
	//printf("length=%d\n",length(l));
	print_int_list(l);
	l = func(max,l);
	//print_int_list(l);
	return 0;
}
