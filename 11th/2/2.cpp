// 2.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char buf[128];

typedef int datatype;
struct node {
	datatype data;
	struct node *left;
	struct node *right;
};

struct node* get_tree() {
	struct node* t;
	if (fgets(buf, sizeof(buf), stdin) == NULL || buf[0] == '.') {
		return NULL;
	}
	else {
		t = (struct node*)malloc(sizeof(struct node));
		sscanf(buf, "%d ", &t->data);
		t->left = get_tree();
		t->right = get_tree();
		return t;
	}
}

void print_tree(struct node* t) {
	//うめる
	if (t == NULL) {
		printf("-");
	}
	else {
		printf("%d(",t->data);
		print_tree(t->left);
		printf(",");
		print_tree(t->right);
		printf(")");
	}
}

int size(struct node* t){
	int l = 0;
	int r = 0;
	if (t == NULL) {
		return 0;
	}
	else {
		l = size(t->left);
		r = size(t->right);
		return l + r + 1;
	}
}

int height(struct node* t){
	//一番上(根)から先端(葉までの節の個数)
	int left = 0;
	int right = 0;
	if (t == NULL) {
		return 0;
	}
	left = height(t->left) + 1;
	right = height(t->right) + 1;
	//右と左を比べて、大きいほうを返す
	if (left > right) {
		return left;
	}
	else {
		return right;
	}
}

int sum(struct node *t){
	int answer = 0;
	if (t == NULL) {
		return 0;
	}
	else {
		return answer = sum(t->left) + sum(t->right) + t->data;
	}
}

int main(){
    struct node *t = get_tree();
    printf("%d\n",size(t));
    printf("%d\n",height(t));
    printf("%d\n",sum(t));
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
