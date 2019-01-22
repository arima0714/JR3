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
	struct node** temp = adjlist;
	struct node* node_one;
	struct node* node_two;
	struct node* temp_node;
	if(temp[eki1] == NULL){
		node_one = (struct node*)malloc(sizeof(struct node));
		node_one->eki = eki2;
		node_one->rosen = rosen;
		node_one->kyori = kyori;
		node_one->next = NULL;
		temp[eki1] = node_one;
	}
	else{
		temp_node = temp[eki1];
		while(temp_node->next != NULL || temp_node->eki > eki1){
			temp_node = temp_node->next;
		}
		node_one = (struct node*)malloc(sizeof(struct node));
		node_one->eki = eki2;
		node_one->rosen = rosen;
		node_one->kyori = kyori;
		node_one->next = temp_node->next;
		temp_node->next = node_one;
	}

	if(temp[eki2] == NULL){
		printf("hel\n");
		node_two = (struct node*)malloc(sizeof(struct node));
	        node_two->eki = eki2;
		node_two->rosen = rosen;
		node_two->kyori = kyori;
		node_two->next = NULL;
		temp[eki2] = node_two;
	}
	else{
		printf("here\n");
		temp_node = temp[eki2];
		while(temp_node->next != NULL || temp_node->eki > eki2){
		temp_node = temp_node->next;
		}
		node_two = (struct node*)malloc(sizeof(struct node));
		node_two->eki = eki1;
		node_two->rosen = rosen;
		node_two->kyori = kyori;
		node_two->next = temp_node->next;
		temp_node->next = node_two;
	}
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
