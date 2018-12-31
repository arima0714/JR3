// 8.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	int id;
	char name[32];
	int score;
};

typedef struct student datatype;

struct node {
	datatype data;
	struct node* left;
	struct node* right;
};

void bst_insert(struct node* t, struct student d) {
	struct node* temp;
	struct node* dummy;
	struct node* new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = d;
	temp = t;
	dummy = t->left;
	new_node->left = dummy;
	new_node->right = dummy;
	if (temp->right == dummy) {
		//tが根の時
		temp->right = new_node;
		new_node->left = dummy;
		new_node->right = dummy;
		return;
	}
	temp = temp->right;
	while (temp != dummy) {
		if (temp->data.id < d.id) {
			//右を調べる
			if (temp->right == dummy) {
				//挿入
				temp->right = new_node;
				new_node->left = dummy;
				new_node->right = dummy;
				return;
			}
			temp = temp->right;
		}
		else {
			//左を調べる
			if (temp->left == dummy) {
				//挿入
				temp->left = new_node;
				new_node->left = dummy;
				new_node->right = dummy;
				return;
			}
			temp = temp->left;
		}
	}
}

void print_bst_dummy(struct node* t, struct node* dummy) {
	if (t == dummy) {
		printf(".\n");
	}
	else {
		printf("%d,%s,%d\n", t->data.id, t->data.name, t->data.score);
		print_bst_dummy(t->left, dummy);
		print_bst_dummy(t->right, dummy);
	}
	return;
}

void print_bst(struct node* t) {
	print_bst_dummy(t->right, t->left);
	return;
}

void find_info(struct node* t, int id) {
	t->left->data.id = id;
	struct node* temp;
	temp = t;
	temp = temp->right;
	while (temp->data.id != id) {
		if (temp->data.id < id) {
			temp = temp->right;
		}
		else {
			temp = temp->left;
		}
	}
	if (temp == temp->right) {
		printf("Not found.\n");
	}
	else {
		printf("%s,%d\n",temp->data.name, temp->data.score);
	}
}

int main()
{
	char buf[128];
	char c;
	int id;
	struct node* t = (struct node*)malloc(sizeof(struct node));
	struct node* dummy = (struct node*)malloc(sizeof(struct node));
	struct student st;
	t->left = t->right = dummy->left = dummy->right = dummy;
	while (fgets(buf, sizeof(buf), stdin) != NULL) {
		sscanf(buf, "%d%c", &id, &c);
		if (c == ',') {
			sscanf(buf, "%d,%[^,],%d", &st.id, st.name, &st.score);
			bst_insert(t, st);
		}
	}
	print_bst(t);
	find_info(t, id);
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
