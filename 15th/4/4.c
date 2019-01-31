﻿#define _CRT_SECURE_NO_WARNINGS
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROSENZU "rosenzu.txt"
#define SETMAX 1600

char buf[256];
int dist[SETMAX];

struct node {
    int eki;
    int rosen;
    int kyori;
    struct node* next;
};

struct set {
    int elements[SETMAX];
    int size;
};

void init_set(struct set* p, int n, int e)
{
    int j = 0;
    int i = 0;
    #ifdef DEBUG
    printf("n = %d`\n",n);
    #endif
    p->size = n - 1;
    #ifdef DEBUG
    printf("after `p->size = n - 1`\n");
    #endif
    while (i < n) {
        if (i != e) {
            p->elements[j] = i;
            j++;
        }
        i++;
    }
}

int delete_min(struct set* p)
{
    int min;
    int i = 0;
    int min_index = 0;
    if (p->size == 0) {
        return -1;
    } else {
        min = dist[0];
        for (i = 0; i < p->size; i++) {
            if (min > dist[p->elements[i]]) {
                min = dist[p->elements[i]];
                min_index = i;
            }
        }
        min = p->elements[min_index];
        p->elements[min_index] = p->elements[p->size - 1];
        p->size--;
    }
    return min;
}

void add_edge(struct node* adjlist[], int eki1, int eki2, int rosen, int kyori)
{
    struct node* new_node_1;
    struct node* new_node_2;
    new_node_1 = (struct node*)malloc(sizeof(struct node));
    new_node_2 = (struct node*)malloc(sizeof(struct node));
    new_node_1->eki = eki2;
    new_node_2->eki = eki1;
    new_node_1->kyori = kyori;
    new_node_2->kyori = kyori;
    new_node_1->rosen = rosen;
    new_node_2->rosen = rosen;

    if (adjlist[eki1] == NULL) {
        adjlist[eki1] = new_node_1;
        new_node_1->next = NULL;
    } else {
        new_node_1->next = adjlist[eki1];
        adjlist[eki1] = new_node_1;
    }
    if (adjlist[eki2] == NULL) {
        adjlist[eki2] = new_node_2;
        new_node_2->next = NULL;
    } else {
        new_node_2->next = adjlist[eki2];
        adjlist[eki2] = new_node_2;
    }
}

int dijkstra(struct node* adjlist[], int eki1, int eki2, int ekisu)
{
    int cur;
    struct node* temp;
    //1
    for (int i = 0; i < SETMAX; i++) {
        if (i != eki1) {
            dist[i] = INT_MAX;
        } else {
            dist[i] = 0;
        }
    }
    //2
    cur = eki1;
    struct set unknown;
    init_set(&unknown, ekisu, eki1);
    //3
    while(unknown.size != 0 || cur != eki2){
        #ifdef DEBUG
        printf("before 3-i\n");
        #endif
        //i
        temp = adjlist[cur];
        while(temp != NULL){
            dist[temp->eki] = dist[cur] + temp->kyori;
            temp = temp->next;
        }
        #ifdef DEBUG
        printf("before 3-ii\n");
        #endif
        //ii
        cur = delete_min(&unknown);
    }
    #ifdef DEBUG
    printf("before 4\n");
    #endif
    //4
    return dist[eki2];
}

int main()
{
    int eki1;
    int eki2;
    int rosen;
    int ekisu;
    int i;
    int kyori;
    FILE* fp = fopen(ROSENZU, "r");
    fscanf(fp, "%d ", &ekisu);
    struct node* adjlist[ekisu]; //ekisuが定数でないと怒られる
    for (i = 0; i < ekisu; ++i) {
        adjlist[i] = NULL;
    }
    while (fgets(buf, sizeof(buf), fp) != NULL) {
        sscanf(buf, "%d:%d:%d:%d ", &eki1, &eki2, &rosen, &kyori);
        add_edge(adjlist, eki1, eki2, rosen, kyori);
    }
    fclose(fp);
    scanf("%d %d ", &eki1, &eki2);
    #ifdef DEBUG
    printf("before excuting dijkstra\n");
    #endif
    printf("%d\n", dijkstra(adjlist, eki1, eki2, ekisu));
    return 0;
}
