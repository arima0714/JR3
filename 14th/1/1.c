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

void put_node(struct node* list, int eki, int rosen, float kyori)
{
    struct node* new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->eki = eki;
    new_node->kyori = kyori;
    new_node->rosen = rosen;
    if (list == NULL) {
        new_node->next = NULL;
    } else {
        new_node->next = list->next;
        list->next = new_node;
    }
}

void add_edge(struct node* adjlist[], int eki1, int eki2, int rosen, float kyori)
{
    struct node* new_n1;
    struct node* new_n2;
    //eki1連結リストの先頭にeki2を含むnodeを追加
    put_node(adjlist[eki1], eki2, rosen, kyori);
    //eki2連結リストの先頭にeki1を含むnodeを追加
    put_node(adjlist[eki2], eki1, rosen, kyori);
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