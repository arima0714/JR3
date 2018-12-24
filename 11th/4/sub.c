// 4.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char buf[128];

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

struct node* get_tree() {
	struct node *t;
	if (fgets(buf, sizeof(buf), stdin) == NULL || buf[0] == '.') {
		return NULL;
	}
	else {
		t = (struct node*)malloc(sizeof(struct node));
		sscanf(buf, "%d,%[^,],%d", &t->data.id, &t->data.name, &t->data.score);
		t->left = get_tree();
		t->right = get_tree();
		return t;
	}
}

void find_info(struct node *t, int id) {
	while (t != NULL) {
		if (t->data.id == id) {
			printf("%s,%d\n", t->data.name, t->data.score);
			return 0;
		}
		else if (id < t->data.id) {
			t = t->left;
		}
		else {
			t = t->right;
		}
	}
	printf("Not found.\n");
}

int main()
{
	int id;
	struct node *t = get_tree();
	scanf("%d ", &id);
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
