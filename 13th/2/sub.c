// 2.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLACK 1
#define RED 0

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
    } else {
        t = (struct rb_node*)malloc(sizeof(struct rb_node));
        sscanf(buf, "[%c]%d,%[^,],%d", &c, &t->data.id, &t->data.name, &t->data.score);
        t->black = (c == 'b');
        t->left = get_rbtree();
        t->right = get_rbtree();
        return t;
    }
}

void print_rbtree(struct rb_node* t)
{
    if (t == NULL) {
        printf(".\n");
    } else {
        printf("[%c]%d,%s,%d\n", t->black ? 'b' : 'r', t->data.id, t->data.name, t->data.score);
        print_rbtree(t->left);
        print_rbtree(t->right);
    }
}

// 1. 葉は必ず黒

int is_black(struct rb_node* t) {
	return (t == NULL || t->black);
}

bool rule_2(struct rb_node* t) {
	int parent_color;
	int left_child_color;
	int right_child_color;
	bool left_result;
	bool right_result;
	parent_color = is_black(t);
	// 2. 赤の節点の子は必ず黒
	if (t == NULL) {
		return true;
	}
	else {
		left_child_color = is_black(t->left);
		right_child_color = is_black(t->right);
		if (parent_color == RED) {
			if (left_child_color == RED) {
				return false;
			}
			else if (right_child_color == RED) {
				return false;
			}
		}
		left_result =  rule_2(t->left);
		right_result = rule_2(t->right);
		if (left_result == true && right_result == true) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool rule_3_rec(struct rb_node* t) {
	int left_result;
	int right_result;
	if (t == NULL) {
		return true;
	}
	else {
		left_result = rule_3_rec(t->left);
		right_result = rule_3_rec(t->right);
		if (left_result == true && right_result == true) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool rule_3(struct rb_node* t) {
	// 3. 根から葉にたどり着くまで通る黒い節点の数がすべて同じ
	// 深さ優先探索でNULLまでの距離を探していく…
	bool left_result;
	bool right_result;
	left_result = rule_3_rec(t->left);
	right_result = rule_3_rec(t->right);
	return (left_result == true && right_result == true);
}

bool is_rbtree(struct rb_node* t){
	if (rule_2(t) == false) {
		return false;
	}
	if (rule_3(t) == false) {
		return false;
	}
    return true;
}

int main()
{
    struct rb_node* t = get_rbtree();
    if(is_rbtree(t)){
        printf("Yes.\n");
    }else{
        printf("No.\n");
    }
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
