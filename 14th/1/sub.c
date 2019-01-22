#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[256];

struct node {
	int eki;
	int rosen;
	float kyori;
	struct node* next;
};

void add_edge(struct node* adjlist[], int eki1, int eki2, int rosen, float kyori) {

}

void print_adjlist(struct node* adjlist[], int n) {
	int i;
	struct node* p;
	for (i = 0; i < n;++i) {
		printf("%d:", i);
		p = adjlist[i];
		while (p != NULL) {
			printf(" (%d,%d,%.3f)", p->eki, p->rosen, p->kyori);
			p = p->next;
		}
		printf("\n");
	}
	return;
}

int main()
{
	int eki1;
	int eki2;
	int rosen;
	int ekisu;
	int i;
	float kyori;
	scanf("%d ", &ekisu);
	struct node* adjlist[ekisu];
	for (i = 0;i < ekisu;++i) {
		adjlist[i] = NULL;
	}
	while (fgets(buf, sizeof(buf), stdin) != NULL) {
		sscanf(buf, "%d:%d:%d:%f ", &eki1, &eki2, &rosen, &kyori);
		add_edge(adjlist, eki1, eki2, rosen, kyori);
	}
	print_adjlist(adjlist, ekisu);
	return 0;
}
