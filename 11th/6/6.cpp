#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char buf[128];

struct student {
	int id;
	char name[32];
	int score;
};

typedef struct student datatype;

struct node {
	datatype data;
	struct node *left;
	struct node *right;
};

struct node *get_tree()
{
	struct node *t;
	if (fgets(buf, sizeof(buf), stdin) == NULL || buf[0] == '.') {
		return NULL;
	} else {
		t = (struct node *)malloc(sizeof(struct node));
		sscanf(buf, "%d,%[^,],%d", &t->data.id, t->data.name,
		       &t->data.score);
		t->left = get_tree();
		t->right = get_tree();
		return t;
	}
}

void print_bst(struct node *t)
{
	if (t == NULL) {
		printf(".\n");
	} else {
		printf("%d,%s,%d\n", t->data.id, t->data.name, t->data.score);
		print_bst(t->left);
		print_bst(t->right);
	}
}
//tの指す節点を根とする二分探索木から、学籍番号がidと一致する学生の節点を削除し、得られた二分探索木の根の節点のアドレスを返す関数
struct node* bst_delete(struct node *t,int id){
	struct node *n;
	struct node *tmp;
	tmp = t;
	while (true) {
		if (tmp->data.id == id) {
			break;
		}
		else {
			if (tmp->data.id < id) {
				tmp = tmp->right;
			}
			else {
				tmp = tmp->left;
			}
		}
	}
	printf("%d,%s,%d\n", tmp->data.id, tmp->data.name, tmp->data.score);
	return t;
    //削除すべきデータをnとする
    //nの右の子が葉であるとき、nがあったところにnの左の子がそのまま入る
    //nの右の子の左の子が葉であるとき、nがあったところにはnの右の子の節点が入り、その左の子としてnの左の子が、右の子としてnの右の子の右の子が入る
    //そうでなければ、n
}

int main()
{
    struct node *t = get_tree();
    int id;
    scanf("%d ",&id);
    t = bst_delete(t,id);
    print_bst(t);
	return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
