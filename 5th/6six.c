#include <stdio.h>
#include <stdlib.h>

typedef int elementtype;

struct node{
	elementtype element;
	struct node *next;
};

typedef struct node *list;

list cons(elementtype e,list l){
	struct node *temp_one;
	temp_one = (struct node *)malloc(sizeof(struct node));
	struct node *temp_two;
	temp_two = (struct node *)malloc(sizeof(struct node));
	struct node *content;
	content = (struct node *)malloc(sizeof(struct node));

	content->element = e;
	content->next = NULL;
	
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
	struct node *temp;
	temp = l;
	while(temp != NULL){
		printf("[%d]",temp->element);
		temp = temp->next;
	}
	printf("\n");
}
list func(list max, list l){
	struct node *temp_one;
	struct node *temp_two;
	struct node *temp_three;

	//printf("here!\n");

	temp_one = (struct node *)malloc(sizeof(struct node));
	temp_two = (struct node *)malloc(sizeof(struct node));
	temp_three = (struct node *)malloc(sizeof(struct node));
	
	temp_one = max;
	//printf("here!\n");
	while(temp_one->next != NULL){
		temp_one = temp_one->next;
	}
	temp_one->next = l;
	
	temp_two = max;
	//printf("here@\n");
	while(1){
		if(temp_two->next == max){
			temp_two->next = NULL;
			break;
		}else{
			temp_two = temp_two->next;
		}
	}
	
	return max;
}

int main(){
	int i;
	int f = 0;
	char buf[128];
	struct node *l;
	struct node *temp;
	l = (struct node *)malloc(sizeof(struct node));
	struct node *max;
	max = (struct node*)malloc(sizeof(struct node));
	max->element = -10000;
	while(fgets(buf,sizeof(buf),stdin) != NULL){
		sscanf(buf, "%d", &i);
		cons(i,l);
	}
	temp = l;
	//printf("here!\n");
	while(temp != NULL){
		if(f == 0){
			f++;
		}
		else if(temp->element >= max->element){
			max = temp;
		}
		temp = temp->next;
	}
	l = l->next;
	//printf("length=%d\n",length(l));
	//print_int_list(l);
	//printf("max->element = %d\n",max->element);
	//printf("max->next->element = %d\n",max->next->element);
	l = func(max,l);
	print_int_list(l);
	return 0;
}
