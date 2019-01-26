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

void add_edge(struct node* adjlist[], int eki1, int eki2, int rosen, float kyori)
{
    struct node* new_node_1;
    struct node* new_node_2;
    struct node* temp_1;
    struct node* temp_2;
    new_node_1 = (struct node*)malloc(sizeof(struct node));
    new_node_2 = (struct node*)malloc(sizeof(struct node));
    new_node_1->eki = eki2;
    new_node_2->eki = eki1;
    new_node_1->kyori = kyori;
    new_node_2->kyori = kyori;
    new_node_1->rosen = rosen;
    new_node_2->rosen = rosen;


    if(adjlist[eki1] == NULL){
        adjlist[eki1] = new_node_1;
        new_node_1->next = NULL;
    }
	else{
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
    //初期化を実施
    for (i = 0; i < ekisu; ++i) {
        adjlist[i] = NULL;
    }
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        //隣接する駅の情報を読み取り
        sscanf(buf, "%d:%d:%d:%f ", &eki1, &eki2, &rosen, &kyori);
        //データを隣接リスト表現のグラフに追加
        add_edge(adjlist, eki1, eki2, rosen, kyori);
    }
    print_adjlist(adjlist, ekisu);
    return 0;
}

// int main(){
// 	printf("this is test\n");
// 	#ifdef DEBUG
// 	printf("this is DEBUG\n");
// 	#endif
// }//DEBUG時に出す方法