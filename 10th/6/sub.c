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
	char name[32];
	int score;
};

struct node {
	struct student data;
	struct node *next;
};

int hash(char *s) {
	//埋める
	int i = 0;
	int S = 0;
	//int base = 1;
	S = s[i] % SIZE;
	while (s[i] != 0) {
		if (i != 0) {
			S = (S * 128 + s[i]) % SIZE;
		}
		else if (i == 0) {
			S = s[i] % SIZE;
		}
		i++;
	}
	return S;
}

//一致する場合は加算する関数
int add_score(struct node *table[], char *s, struct student st) {
	//埋める
	struct node* target;
	target = table[hash(s)];
	while (target != NULL) {
		//検索文字列と同じとき
		if (strcmp(s, target->data.name) == 0) {
			target->data.score += st.score;
			return 1;
		}
		//検索文字列と異なる時
		else {
			target = target->next;
		}
	}
	return 0;
}


void set_data(struct node *table[], struct student st) {
	int hs = hash(st.name);
	//ハッシュ値を求める
	struct node* B;
	struct node* temp;
	B = (struct node*)malloc(sizeof(struct node));
	B->data = st;
	//データを挿入する場所がNULLの場合
	if (table[hs] == NULL) {
		//printf("NULLの場合です\n");
		table[hs] = B;
		B->next = NULL;
	}
	//NULLでない場合
	else {
		temp = table[hs];
		//printf("NULLでない場合です\n%d,%s,%d\n", st.id, st.name, st.score);
		B->next = table[hs];
		//検索してなければ先頭に挿入
		if (add_score(table, st.name, st)==0) {
			while (temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = B;
			B->next = NULL;
		}
	}
}
int main()
{
	int i;
	char buf[128];
	struct student st;
	struct node *table[SIZE];
	struct node* p;

	for (i = 0;i < SIZE;i++) {
		table[i] = NULL;
	}
	while (fgets(buf, sizeof(buf), stdin) != NULL) {
			sscanf(buf, "%[^,],%d",&st.name, &st.score);
			set_data(table, st);
	}
	for (i = 0;i < SIZE;++i) {
		p = table[i];
		while (p != NULL) {
			st = p->data;
			printf("%s,%d\n",st.name, st.score);
			p = p->next;
		}
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
