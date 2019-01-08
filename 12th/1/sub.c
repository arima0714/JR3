// 1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

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

struct avl_node {
	datatype data;
	struct avl_node *left;
	struct avl_node *right;
	int height;
};


//高さを知ることができる関数
int height(struct avl_node *t) {
	return 0;
}

//左右の部分木の高さが正しく設定されているときにメンバheightを適切に設定しなおす関数
void put_height(struct avl_node *t) {
	if (t == NULL) {
		return;
	}
	if (t->left != NULL && t->right != NULL) {
		if (t->left->height > t->right->height) {
			t->height = t->left->height + 1;
		}
		else {
			t->height = t->right->height + 1;
		}
	}
	else if (t->left != NULL) {
		t->height = t->left->height+1;
	}
	else {
		t->height = t->right->height+1;
	}
}

struct avl_node *get_avl() {
	struct avl_node *t;
	if (fgets(buf, sizeof(buf), stdin) == NULL || buf[0] == '.') {
		return NULL;
	}
	else {
		t = (struct avl_node*)malloc(sizeof(struct avl_node));
		sscanf(buf, "[%d]%d,%[^,],%d", &t->height, &t->data.id, t->data.name, &t->data.score);
		t->left = get_avl();
		t->right = get_avl();
		return t;
	}
}

struct avl_node* rotate_right(struct avl_node *t) {
	struct avl_node* large_a = t;
	struct avl_node* large_b = t->left;
	if (large_b == NULL) {
		return t;
	}
	struct avl_node* tree_one = large_b->left;
	struct avl_node* tree_two = large_b->right;
	struct avl_node* tree_thr = large_a->right;
	large_b->left = tree_one;
	large_b->right = large_a;
	large_a->left = tree_two;
	large_a->right = tree_thr;

	put_height(large_a);
	put_height(large_b);
	return large_b;
}

struct avl_node* rotate_left(struct avl_node *t) {
	struct avl_node* large_b = t;
	struct avl_node* large_a = large_b->right;
	if (large_a == NULL) {
		return t;
	}
	struct avl_node* tree_one = large_b->left;
	struct avl_node* tree_two = large_a->left;
	struct avl_node* tree_thr = large_a->right;
	large_a->left = large_b;
	large_a->right = tree_thr;
	large_b->left = tree_one;
	large_b->right = tree_two;

	put_height(large_b);
	put_height(large_a);
	return large_a;
}

void print_avl(struct avl_node *t)
{
	if (t == NULL) {
		printf(".\n");
	}
	else {
		printf("[%d]%d,%s,%d\n", t->height, t->data.id, t->data.name, t->data.score);
		print_avl(t->left);
		print_avl(t->right);
	}
}

int main() {
	struct avl_node *t;
	char c;
	scanf("%c ", &c);
	t = get_avl();
	if (c == 'R') {
		t = rotate_right(t);
	}
	else if (c == 'L') {
		t = rotate_left(t);
	}
	print_avl(t);
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
