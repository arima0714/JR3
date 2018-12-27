// ConsoleApplication3.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

//#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

typedef int elementtype;

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
	new_node->element = -1;
	new_node->next = NULL;
	return new_node;
}

void print_node(struct node* node) {
	while (node != NULL) {
		if (node->element < 0) {
			;
		}
		else {
			printf("%d", node->element);
		}
		node = node->next;
	}
	printf("\n");
}

void sample(void) {
	struct node* node;
	//node = (struct node*)malloc(sizeof(struct node));
	//node->element = -1;
	//node->next = NULL;
	node = init_node();
	add_node(node, 1);
	add_node(node, 0);
	add_node(node, 2);
	add_node(node, 3);
	add_last_node(node, 4);
	add_last_node(node, 5);
	print_node(node);
	print_node(node);
}

int main()
{
	int d;
	char c;
	struct node* input_one;
	struct node* input_two;
	input_one = init_node();
	input_two = init_node();
	int carry = 0;
	struct node* output;
	output = init_node();
	
	/*sample();*/

	//入力された2値を行ごとにそれぞれ、input_one, input_twoに格納
	while ((c = getchar()) != '\n') {
		d = (int)c - '0';
		add_node(input_one, d);
	}
	while ((c = getchar()) != '\n') {
		d = (int)c - '0';
		add_node(input_two, d);
	}
	//入力された2値を出力
	//print_node(input_one);
	//print_node(input_two);
	//加算をする

	while (input_one != NULL || input_two != NULL) {
		int temp_one = 0;
		int temp_two = 0;
		int one_plus_two = 0;

		if (input_one == NULL) {
			;
		}
		else {
			temp_one = input_one->element;
			input_one = input_one->next;
		}
		if (input_two == NULL) {
			;
		}
		else {
			temp_two = input_two->element;
			input_two = input_two->next;
		}
		one_plus_two = temp_one + temp_two + carry;
		if (one_plus_two >= 10) {
			carry = 1;
			one_plus_two = one_plus_two - 10;
		}
		else {
			carry = 0;
		}
		add_node(output, one_plus_two);

	}

	if (carry != 0) {
		add_node(output, carry);
	}

	print_node(output);



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
