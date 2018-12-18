#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char buf[128];

typedef char datatype;

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

	}

	else {

		t = (struct node *)malloc(sizeof(struct node));

		sscanf(buf, "%c ", &t->data);

		t->left = get_tree();

		t->right = get_tree();

		return t;

	}

}

void print_preorder(struct node *t)
{

	if (t == NULL) {

		;

	}

	else {

		printf("%c", t->data);

		print_preorder(t->left);

		print_preorder(t->right);

	}

}

void print_inorder(struct node *t)
{

	if (t == NULL) {
	} else {

		print_inorder(t->left);

		printf("%c", t->data);

		print_inorder(t->right);
	}

}

void print_postorder(struct node *t)
{

	if (t == NULL) {
	} else {

		print_postorder(t->left);

		print_postorder(t->right);

		printf("%c", t->data);
	}

}

int main()
{

	struct node *t = get_tree();

	print_preorder(t);

	printf("\n");

	print_inorder(t);

	printf("\n");

	print_postorder(t);

	printf("\n");

	return 0;

}

// プログラムの実衁E Ctrl + F5 また�E [チE��チE��] > [チE��チE��なしで開始] メニュー
// プログラムのチE��チE��: F5 また�E [チE��チE��] > [チE��チE��の開始] メニュー

// 作業を開始するため�EヒンチE 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管琁E��まぁE
//   2. チ�Eム エクスプローラー ウィンドウを使用してソース管琁E��接続しまぁE//   3. 出力ウィンドウを使用して、ビルド�E力とそ�E他�EメチE��ージを表示しまぁE//   4. エラー一覧ウィンドウを使用してエラーを表示しまぁE//   5. [プロジェクチE > [新しい頁E��の追加] と移動して新しいコーチEファイルを作�Eするか、[プロジェクチE > [既存�E頁E��の追加] と移動して既存�EコーチEファイルを�Eロジェクトに追加しまぁE//   6. 後ほどこ�Eプロジェクトを再�E開く場合、[ファイル] > [開く] > [プロジェクチE と移動して .sln ファイルを選択しまぁE