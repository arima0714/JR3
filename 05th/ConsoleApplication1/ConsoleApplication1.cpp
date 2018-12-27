// ConsoleApplication3.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

typedef char elementtype;

struct node {
	elementtype element;
	struct node *next;
};

//第一引数のノードの次にeの値を持つノードを追加します
void add_node(struct node* node, elementtype e) {
	struct node* new_content;
	new_content = (struct node *)malloc(sizeof(struct node));
	new_content->element = e;
	new_content->next = node->next;
	node->next = new_content;
}

void add_last_node(struct node* node, elementtype e) {
	//新しく追加するノードの初期設定を行います
	struct node* new_content;
	new_content = (struct node *)malloc(sizeof(struct node));
	new_content->element = e;
	//与えられたノードの最後になるまでループを回します
	while (node->next != NULL) {
		node = node->next;
	}
	new_content->next = node->next;
	node->next = new_content;
}

struct node* init_node(void) {
	struct node* new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	//new_node->element = -1;
	new_node->next = NULL;
	return new_node;
}

void print_node(struct node* node) {
	node = node->next;
	while (node != NULL) {
		printf("%c", node->element);
		node = node->next;
	}
	printf("\n");
}

void func(struct node *node, struct node* output) {

}

int main()
{
	char d;
	char c;
	struct node* input_one;
	input_one = init_node();
	struct node* output;
	output = init_node();

	//入力された2値を行ごとにそれぞれ、input_one, input_twoに格納
	while ((c = getchar()) != '\n') {
		d = c;
		add_last_node(input_one, d);
	}

	print_node(input_one);


	//printf("hello world\n");
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
