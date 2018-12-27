#include <stdio.h>
#include <stdlib.h>

typedef int elementtype;

struct node {
    elementtype element;
    struct node* next;
};

typedef struct node* list;

list cons(elementtype e, list l)
{
    struct node* first;
    first = (struct node*)malloc(sizeof(struct node));
    first->next = l;
    first->element = e;
    return first;
}

void delete(list l){
	// printf("before\n");
	free(l->next);
	// printf("after\n");
	l->next = l->next->next;
}

int length(list l)
{
    int len_list = 0;
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->next = l;
    temp->next = temp->next->next;

    while (temp->next != NULL) {
        len_list++;
        temp->next = temp->next->next;
    }

    return len_list;
}

void print_int_list(list l)
{
    l = l->next;
    while (l != NULL) {
        printf("%d\n", l->element);
        l = l->next;
    }
}

void print_int_list_d(list l)
{
    l = l->next;
    while (l != NULL) {
        printf("[%d]", l->element);
        l = l->next;
    }
	printf("\n");
}

void insert(elementtype e,list l)
{
    struct node* new = (struct node*)malloc(sizeof(struct node));
    struct node* content = (struct node*)malloc(sizeof(struct node));
    // printf("here@\n");
    content = l;
    new->element = e;
    new->next = content->next;
    content->next = new;
    // print_int_list(l);
}

int abs(elementtype i)
{
    if (i < 0) {
        return i * -1;
    } else {
        return i;
    }
}

//struct node *

int main()
{
    int i;
    int max;
    char buf[128];
    list l;
    list last;
    list temp;
    max = 0;
    last = (struct node*)malloc(sizeof(struct node));
    last->next = last;
    l = last;
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        int j = 0;
        sscanf(buf, "%d", &i);
        //printf("i = %d\n",i);
        struct node* temp;
        temp = last;
        if (max == 0) {//最初にリストに入れる際の処理
            temp->next = cons(i, NULL);
        } else {
            while (1) {
                //printf("max = %d ",max);
                //printf("j = %d ",j);
                //printf("temp->element = %d ",temp->element);
                //printf("i = %d ",i);
                //printf("\n");
                if (j < max) {
                    if(i == 0){
                        if(temp->next->element == i){
                            max--;
                            break;
                        }
                    }
                    else if(i != 0){
                        if(temp->element == i){//重複除け
                            max--;
                            break;
                        }
                        else if(temp->next->element == i){//重複除け
                            max--;
                            break;
                        }
                        if(abs(i) > abs(temp->next->element)){//基本的な順番を作成する
                            //printf("abs(i) > abs(temp->element)\n");
                            insert(i, temp);
                            break;
                        }
                        if(abs(i) == abs(temp->next->element)){
                            if(i < temp->next->element){
                                //printf("here\n");
                                ;
                            }
                            else{
                                //printf("abs(i) == abs(temp->element)\n");
                                insert(i, temp);
                                break;
                            }
                        }
                    }
                    if(abs(temp->element) >= abs(i) && abs(i) > abs(temp->next->element)){
                        //printf("abs(temp->element) >= abs(i) && abs(i) >= abs(temp->next->element)\n");
                        insert(i,temp->next);
                        break;
                    }
                } else if (max == j) {                    
                    temp->next = cons(i, NULL);
                    break;
                }
                j++;
                temp = temp->next;
            }
        }
    	//print_int_list_d(l);
        max++;
    }
    temp = l;
    print_int_list(temp);
    return 0;
}
