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
		printf("[%d]",l->element);
		l = l->next;
	}
	printf("\n");
}


int main(){
	int i;
	char buf[128];
	list l;
	list last;
	last = (struct node *)malloc(sizeof(struct node));
	last->next = last;
	l = last;
	while(fgets(buf,sizeof(buf),stdin) != NULL){
		sscanf(buf, "%d", &i);
		last->next = cons(i,NULL);
		last = last->next;
	}
	printf("length=%d\n",length(l));
	print_int_list(l);
	return 0;
}
