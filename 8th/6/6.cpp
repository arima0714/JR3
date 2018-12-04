#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int count = 0;
char kijun;
struct point {
	int x;
	int y;
};
typedef struct point elementtype;

struct node {
	elementtype element;
	struct node *next;
};
typedef struct node* list;

//p1,p2を比較する関数. p1>p2 => 1,p1==p2 => 0, p1<p2 => -1
int compare_by(struct point p1, struct point p2) {
	count++;
	//ここを埋める
	if (p1.x == p2.x && p1.y == p2.y) {
		return 0;
	}
	else if (kijun == 'X') {//Xの処理
		if (p1.x > p2.x) {
			return 1;
		}
		else if (p1.x < p2.x) {
			return -1;
		}
		else if (p1.y > p2.y) {
			return 1;
		}
		else {
			return -1;
		}
	}
	else if (kijun == 'Y') {//Yの処理
		if (p1.y > p2.y) {
			return 1;
		}
		else if (p1.y < p2.y) {
			return -1;
		}
		else if (p1.x > p2.x) {
			return 1;
		}
		else {
			return -1;
		}
	}
	else {//Dの処理
		int p1xy = p1.x * p1.x + p1.y * p1.y;
		int p2xy = p2.x * p2.x + p2.y * p2.y;
		if (p1xy > p2xy) {
			return 1;
		}
		else if (p1xy < p2xy) {
			return -1;
		}
		else if (p1.x > p2.x) {
			return 1;
		}
		else if (p1.x < p2.x) {
			return -1;
		}
		else if (p1.y > p2.y) {
			return 1;
		}
		else {
			return -1;
		}
	}
}

//l1で渡されるリストを1l,l2に分割する関数（出来ていると思われる）
void split(list l1, list l2) {
	//以下を埋める

	//元のリストlの先頭を示すポインタ変数p1,p2を用意する
	struct node* p1;
	struct node* p2;
	p1 = l1;
	p2 = l1;
	while ((p2 == NULL || p2->next == NULL ||p2->next->next == NULL) != 1) {
		//p2が2つnextをたどるたびにp1が1つnextをたどる
		p2 = p2->next->next;
		p1 = p1->next;
	}
	//p2が2つnextをたどれなくなった時点（p2==NULL || p2->next->next==NULL）
	//	でのp1の指す接点のnextが後半のリストの頭のnextとなるようにし、p1が指す接点のnextをNULLとする
	l2->next = p1->next;
	p1->next = NULL;
}

void merge(list l1, list l2) {
	//以下を埋める
	struct node* return_list;
	struct node* return_list_last;
	int result = 0;
	l1 = l1->next;
	l2 = l2->next;
	return_list = return_list_last = (struct node*)malloc(sizeof(struct node));
	while (l1 != NULL && l2 != NULL) {
		result = compare_by(l1->element, l2->element);
		if(result != 1){
			return_list_last = return_list_last->next = (list)malloc(sizeof(struct node));
			return_list_last->element = l1->element;
			l1 = l1->next;
		}
		else {
			return_list_last = return_list_last->next = (list)malloc(sizeof(struct node));
			return_list_last->element = l2->element;
			l2 = l2->next;
		}
	}
	if (l1 == NULL) {
		return_list_last = return_list_last->next = (list)malloc(sizeof(struct node));
		return_list_last->next = l2;
	}
	else {
		return_list_last = return_list_last->next = (list)malloc(sizeof(struct node));
		return_list_last->next = l1;
	}
	l1 = return_list;
}

void merge_sort(list l) {
	//以下を埋める
	if (l != NULL && l->next != NULL && l->next->next != NULL){
		struct node* l1;
		struct node* l2;
		l1 = l;
		l2 = (struct node*)malloc(sizeof(struct node));
		split(l1, l2);
		merge_sort(l1);
		merge_sort(l2);
		merge(l1, l2);
		l = l1;
	}
}

int main() {
	char buf[128];
	struct point p;
	list l;
	list last;
	scanf("%c ", &kijun);
	last = l = (list)malloc(sizeof(struct node));
	while (fgets(buf, sizeof(buf), stdin) != NULL) {
		sscanf(buf, "%d %d", &p.x, &p.y);
		last = last->next = (list)malloc(sizeof(struct node));
		last->element = p;
	}
	last->next = NULL;

	merge_sort(l);

	printf("%d\n", count);
	while ((l = l->next) != NULL) {
		p = l->element;
		printf("%d %d\n", p.x, p.y);
	}
	return 0;
}