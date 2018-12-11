// 5.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 101

struct student {
	int id;
	char name[32];
	int score;
};

struct node {
	struct student data;
	struct node *next;
};

int hash(char *s) {
	//問題４と同じ
}

void set_data(struct node *table[], struct student st) {
	//問題４と同じ
}

int find_score(struct node *table[], char *s) {
	//埋める
}

int main()
{
	int i;
	int v;
	char buf[128];
	char name[32];
	struct student st;
	struct node *table[SIZE];

	for (i = 0;i < SIZE;i++) {
		table[i] = NULL;
	}
	while (fgets(buf, sizeof(buf), stdin) != NULL) {
		sscanf(buf, "%d,", &v);
		if (v > 0) {
			sscanf(buf, "%d,%[^,],%d", &st.id, &st.name, &st.score);
			set_data(table, st);
		}
		else {
			sscanf(buf, "0,%[^,\n]", name);
		}
	}
	v = find_score(table, name);
	if (v < 0) {
		printf("Not found\n");
	}
	else {
		printf("%d\n", v);
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
