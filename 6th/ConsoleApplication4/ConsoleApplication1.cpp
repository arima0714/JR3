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

//第一引数で渡されるノードの最後尾にeの値を持つノードを追加します
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


//新しくノードの先頭を作る際における初期化を行います
struct node* init_node(void) {
	struct node* new_node;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->element = -1;
	new_node->next = NULL;
	return new_node;
}

//最初に追加された負の値を除くelementを順に表示し、最後に改行します
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

//第一・第二引数を足した結果を第三引数のノードに格納する関数
struct node* add_nodes(struct node* one, struct node* two) {
	int carry = 0;
	struct node* answer;
	struct node* temp_answer;
	answer = init_node();
	temp_answer = answer;
	if (two != NULL) {
		while (two->element < 0) {
			two = two->next;
		}
	}
	if (one != NULL) {
		while (one->element < 0) {
			one = one->next;
		}
	}
	
	while (one != NULL || two != NULL) {
		int temp_one = 0;
		int temp_two = 0;
		int one_plus_two = 0;
		if (one == NULL) {
			;
		}
		else {
			temp_one = one->element;
			one = one->next;
		}
		if (two == NULL) {
			;
		}
		else {
			temp_two = two->element;
			two = two->next;
		}
		one_plus_two = temp_one + temp_two + carry;
		if (one_plus_two >= 10) {
			carry = 1;
			one_plus_two -= 10;
		}
		else {
			carry = 0;
		}
		add_last_node(temp_answer, one_plus_two);
	}
	if (carry != 0) {
		add_last_node(temp_answer, carry);
	}
	return answer;
}

int main()
{
	int d;
	char c;
	struct node* input_one;
	struct node* input_two;
	struct node* temp_input_two;
	input_one = init_node();
	input_two = init_node();
	int carry = 0;
	struct node* output;
	struct node* temp;
	output = init_node();
	int temp_num = 0;

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

	//d は桁数をカウントする
	d = 0;
	input_one = input_one->next;
	input_two = input_two->next;
	output = output->next;
	temp_input_two = input_two;
	while (input_one != NULL) {//筆算の際に下にある方のループ
		temp = init_node();
		//temp = temp->next;
		input_two = temp_input_two;
		while (input_two != NULL) {//筆算の際に上の方にあるループ
			temp_num = input_one->element * input_two->element + carry;
			if (temp_num >= 10) {
				add_last_node(temp, temp_num % 10);
				temp_num /= 10;
				carry = temp_num % 10;
			}
			else {
				add_last_node(temp, temp_num);
				carry = 0;
			}
			input_two = input_two->next;
		}
		if (carry != 0) {
			add_last_node(temp, carry);
			carry = 0;
		}
		for (int i = 0;i != d;i++) {
			add_node(temp, 0);
		}
		d++;
		input_one = input_one->next;
		output = add_nodes(temp, output);
	}

	if (carry != 0) {
		add_node(output, carry);
	}

	struct node* to_output;
	to_output = init_node();

	while (output != NULL) {
		add_node(to_output, output->element);
		output = output->next;
	}

	print_node(to_output);



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
