// 3.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	struct rb_node* left;
	struct rb_node* right;
	int black;
};

int is_red(struct rb_node* t)
{
	return (t != NULL && !t->black);
}

struct rb_node* get_rbtree()
{
	struct rb_node* t;
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

struct rb_node* rotate_right(struct rb_node* t)
{
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

struct rb_node* rotate_left(struct rb_node* t)
{
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

void print_rbtree(struct rb_node* t)
{
	if (t == NULL) {
		printf(".\n");
	}
	else {
		printf("[%c]%d,%s,%d\n", t->black ? 'b' : 'r', t->data.id, t->data.name, t->data.score);
		print_rbtree(t->left);
		print_rbtree(t->right);
	}
}

struct rb_node* resolve_red_pair(struct rb_node* t)
{
	struct rb_node* large_a;
	struct rb_node* large_b;
	struct rb_node* large_c;
	struct rb_node* large_d;
	struct rb_node* t_1;
	struct rb_node* t_2;
	struct rb_node* t_3;
	struct rb_node* t_4;
	if (is_red(t->left) && is_red(t->left->left)) {
		large_a = t;
		large_b = large_a->left;
		large_c = large_b->left;
		large_d = large_a->right;
		t_1 = large_c->left;
		t_2 = large_c->right;
		t_3 = large_b->right;
		t_4 = large_d;
		//case1
		if (is_red(t_4)) {
			//case1.1
			large_a->black = RED;
			large_b->black = BLACK;
			large_c->black = RED;
			large_d->black = BLACK;
			return large_a;
		}
		else {
			//case1.2
			large_a->black = RED;
			large_b->black = BLACK;
			large_c->black = RED;
			large_d->black = BLACK;
			return rotate_right(large_a);
		}
	}
	else if (is_red(t->left) && is_red(t->left->right)) {
		//case2
		large_a = t;
		large_b = large_a->left;
		large_c = large_b->right;
		large_d = large_a->left;
		t_1 = large_b->left;
		t_2 = large_c->left;
		t_3 = large_c->right;
		t_4 = large_d;
		if (is_red(t_4)) {
			//case2.1
			large_a->black = RED;
			large_b->black = BLACK;
			large_c->black = RED;
			large_d->black = BLACK;
			return large_a;
		}
		else {
			//case2.2
			large_a->black = BLACK;
			large_b->black = RED;
			large_c->black = RED;
			large_d->black = BLACK;
			return resolve_red_pair(rotate_left(large_a));
		}
	}
	else if (is_red(t->right) && is_red(t->right->left)) {
		//case3//case2の左右逆
		large_a = t;
		large_b = large_a->right;
		large_c = large_b->left;
		large_d = large_a->right;
		t_1 = large_b->right;
		t_2 = large_c->right;
		t_3 = large_c->left;
		t_4 = large_d;
		//case3.1
		if (is_red(t_4)) {
			large_a->black = RED;
			large_b->black = BLACK;
			large_c->black = RED;
			large_d->black = BLACK;
		}
		else {
			//case3.2
			large_a->black = BLACK;
			large_b->black = RED;
			large_c->black = RED;
			large_d->black = BLACK;
			return resolve_red_pair(rotate_right(large_a));
		}
	}
	else if (is_red(t->right) && is_red(t->right->right)) {
		//case4//case1の左右逆
		large_a = t;
		large_b = large_a->right;
		large_c = large_b->right;
		large_d = large_a->left;
		t_1 = large_c->right;
		t_2 = large_c->left;
		t_3 = large_b->left;
		t_4 = large_d;
		if (is_red(t_4)) {
			//case4.1
			large_a->black = RED;
			large_b->black = BLACK;
			large_c->black = RED;
			large_d->black = BLACK;
			return large_a;
		}
		else {
			//case4.2
			large_a->black = RED;
			large_b->black = BLACK;
			large_c->black = RED;
			large_d->black = BLACK;
			return rotate_left(large_a);
		}
	}
}

int main()
{
	struct rb_node* t = get_rbtree();
	t = resolve_red_pair(t);
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
