#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buf[256];

void output()
{
#ifdef DEBUG
    printf("this is DEBUG\n");
#endif
} //DEBUG時に出す方法

struct node {
    int eki;
    int rosen;
    float kyori;
    struct node* next;
};

void add_edge(struct node* adjlist[], int eki1, int eki2, int rosen, float kyori)
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

void print_adjlist(struct node* adjlist[], int n)
{
    int i;
    struct node* p;
    for (i = 0; i < n; ++i) {
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

float two_hop_kyori(struct node* adjlist[], int eki)
{
    float answer = 0;
    float temp = 0;
    struct node* temp_list_1;
    struct node* temp_list_2;
#ifdef DEBUG
    printf("target eki = %d\n", eki);
#endif
    temp_list_1 = adjlist[eki];
    while (temp_list_1 != NULL) {
        temp_list_2 = adjlist[temp_list_1->eki];
        while (temp_list_2 != NULL) {
            temp = temp_list_1->kyori + temp_list_2->kyori;
            if (eki != temp_list_2->eki && answer < temp) {
#ifdef DEBUG
                printf("temp_list_1 eki = %d,kyori = %f\n", temp_list_1->eki, temp_list_1->kyori);
                printf("temp_list_2 eki = %d,kyori = %f\n", temp_list_2->eki, temp_list_2->kyori);
#endif
                answer = temp;
            }
            temp_list_2 = temp_list_2->next;
        }
        temp_list_1 = temp_list_1->next;
    }
#ifdef DEBUG
    printf("%d's answer = %f\n", eki, answer);
#endif
    return answer;
}

int main()
{
    int ekisu;
    int eki1;
    int eki2;
    int rosen;
    float kyori;
    scanf("%d ", &ekisu);
    int adjmat[ekisu][ekisu];
    for (int i = 0; i < ekisu; i++) {
        for (int j = 0; j < ekisu; j++) {
            adjmat[i][j] = 0;
        }
    }
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        //隣接する駅の情報を読み取り
        sscanf(buf, "%d:%d:%d:%f ", &eki1, &eki2, &rosen, &kyori);
        adjmat[eki1][eki2] = 1;
        adjmat[eki2][eki1] = 1;
    }
    for (int i = 0; i < ekisu;i++){
        for (int j = 0; j < ekisu;j++){
            printf("%d", adjmat[i][j]);
        }
        printf("\n");
    }
        return 0;
}
