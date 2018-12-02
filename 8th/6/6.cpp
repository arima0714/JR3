#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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

// int compare()

void split(list l1, list l2) {
	//以下を埋める
}

void merge(list l1, list l2) {
	//以下を埋める
}

void merge_sort(list l) {
	//以下を埋める
}

int main() {
	char buf[128];
	struct point p;
	list l;
	list last;
	scanf("%c ", &kijun);
	last = (list)malloc(sizeof(struct node));
	l = last;
	while (fgets(buf, sizeof(buf), stdin) != NULL) {
		sscanf(buf, "%d %d", &p.x, &p.y);
		last->next = (list)malloc(sizeof(struct node));
		last = last->next;
		last->element = p;
	}

}