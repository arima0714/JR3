// 1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define BLACK 1;
#define RED 0;

char buf[128];

struct student {
	int id;
	char name[32];
	int score;
};

typedef struct student datatype;

struct rb_node {
	datatype data;
	struct rb_node *left;
	struct rb_node *right;
	int black;
};

int is_red(struct rb_node* t) {
	return (t != NULL && !t->black);
}

struct rb_node* get_rbtree() {
	struct rb_node *t;
	char c;
	if (fgets(buf, sizeof(buf), stdin) == NULL || buf[0] == '.') {
		return NULL;
	}
	else {
		t = (struct rb_node*)malloc(sizeof(struct rb_node));
		sscanf(buf, "[%c]%d,%[^,],%d", &c, &t->data.id, &t->data.name, &t->data.score);
		t->black = (c == 'b');
		t->left = get_rbtree();
		t->right = get_rbtree();
		return t;
	}
}

struct rb_node* rotate_right(struct rb_node* t) {
	struct rb_node* large_a;
	struct rb_node* large_b;
	struct rb_node* t_1;
	struct rb_node* t_2;
	struct rb_node* t_3;
	large_a = t;
	large_b = large_a->left;
	if (large_b == NULL) {
		return t;
	}
	t_1 = large_b->left;
	t_2 = large_b->right;
	t_3 = large_a->right;
	large_b->right = large_a;
	large_b->left = t_1;
	large_a->left = t_2;
	large_a->right = t_3;
	return large_b;
}

struct rb_node* rotate_left(struct rb_node* t) {
	struct rb_node* large_a;
	struct rb_node* large_b;
	struct rb_node* t_1;
	struct rb_node* t_2;
	struct rb_node* t_3;
	large_b = t;
	large_a = large_b->right;
	if (large_a == NULL) {
		return t;
	}
	t_1 = large_b->left;
	t_2 = large_a->left;
	t_3 = large_a->right;
	large_a->left = large_b;
	large_a->right = t_3;
	large_b->left = t_1;
	large_b->right = t_2;
	return large_a;
}

void print_rbtree(struct rb_node* t) {
	if (t == NULL) {
		printf(".\n");
	}
	else {
		printf("[%c]%d,%s,%d\n", t->black ? 'b' : 'r', t->data.id, t->data.name, t->data.score);
		print_rbtree(t->left);
		print_rbtree(t->right);
	}
}

int main()
{
	struct rb_node* t;
	char c;
	scanf("%c ", &c);
	t = get_rbtree();
	if (c == 'R') {
		t = rotate_right(t);
	}
	else {
		t = rotate_left(t);
	}
	print_rbtree(t);
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
