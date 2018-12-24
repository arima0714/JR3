#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define LEFT 0
#define RIGHT 1

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
    int direction;//探したnodeの方向
    struct node* temp;//探したnodeを指すnode
    struct node* n;//探したnode
	struct node* deleted;
    temp = t;
    while(true){
		if (temp->data.id < id) {
			if (temp->right->data.id == id) {
				direction = RIGHT;
				break;
			}
			else {
				temp = temp->right;
			}
		}
		else {
			if (temp->left->data.id == id) {
				direction = LEFT;
				break;
			}else{
				temp = temp->left;
			}
		}
    }
	;
	if (direction == RIGHT) {
		n = temp->right;
	}
	else {
		n = temp->left;
	}
	deleted = n;
	if (n->right == NULL) {
		if (direction == RIGHT) {
			temp->right = n->left;
		}
		else {
			temp->left = n->left;
		}
		free(deleted);
	}
	else if (n->right->left == NULL) {
		struct node* left;
		struct node* right;
		//"n"の右の子の節点の左の子として"n"の左の子
		n->right->left = n->left;
		//"n"の右の子の節点の右の子として"n"の右の子の右の子
		n->right->right = n->right->right;
		//"n"の部分に"n"の右の子の節点が入る
		if (direction == RIGHT) {
			temp->right = n->right;
		}
		else {
			temp->left = n->right;
		}
		free(deleted);
	}
	else {
		struct node* min;//最小値のアドレス
		struct node* left;//削除されるnodeの左
		struct node* right;//削除されるnodeの右
		struct node* min_root;//最小値を指すnodeのアドレス
		int min_root_dir;
		left = n->left;
		right = n->right;
		//最小値(葉ではない)をn->right->left...->leftのようにして探す
		min = n;
		
		//見つけた最小値を"n"に入れる

		//最小値のあった場所に最小値の右を入れる
	}
	return t;
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
