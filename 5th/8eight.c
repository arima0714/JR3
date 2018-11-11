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

void insert(list l, elementtype e)
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
    // printf("here\n");
    //for(i = 0;(c = buf[i])!= '\n';++i){
    //	last->next = cons(c,NULL);
    //	last = last->next;
    //}
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        int j = 0;
        sscanf(buf, "%d", &i);
        //printf("i = %d\n",i);
        struct node* temp;
        temp = last;
        if (max == 0) {
            temp->next = cons(i, NULL);
        } else {
            while (1) {
                //printf("max = %d, j = %d, temp->element = %d, i = %d\n",max,j,temp->element,i);
                if (j < max) {
                    //printf("j > max\n");
                   
					if(abs(temp->next->element) == abs(i) && temp->next->element < i){
						printf("here!\n");
						insert(temp,i);
						break;
					}
					else if (abs(temp->next->element) < abs(i)) {
                        if (temp->element == i) {
                            break;
                        }
                        printf("here!\n");
                        insert(temp, i);
                        break;
					}
                } else if (max == j) {
					//printf("here@\n");
                    temp->next = cons(i, NULL);
                    break;
                }
                j++;
                temp = temp->next;
            }
        }
    	print_int_list_d(l);
        max++;
    }
	printf("hreadsf\n");
    print_int_list(l);
    return 0;
}