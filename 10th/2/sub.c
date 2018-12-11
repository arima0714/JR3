// 2.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

//#include "pch.h"
//#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int count = 0;

struct student {
	int id;
	char name[32];
	int score;
};

int binary_search(struct student st[], int id, int l, int r) {
	int m;
	++count;
	//埋める
	if (r < l) {
		return -1;
	}
	else {
		m = (l + r) / 2;
		if (st[m].id == id) {
			return m;
		}
		else if (st[m].id < id) {
			binary_search(st, id, m + 1, r);
		}
		else if (st[m].id > id) {
			binary_search(st, id, l, m - 1);
		}
	}
}

int main()
{
	int i = 0;
	int n;
	int v;
	char buf[128];
	char c;
	struct student st[1024];
	while (fgets(buf, sizeof(buf), stdin) != NULL && i < 1024) {
		sscanf(buf, "%d%c", &v, &c);
		if (c == ',') {
			st[i].id = v;
			sscanf(buf, "%*d,%[^,],%d", st[i].name, &st[i].score);
			++i;
		}
	}
	n = i;
	/* この時点で v に探索すべき学籍番号が入っていて，n が読み込んだ要素の数である */
	i = binary_search(st, v, 0, n - 1);
	if (i < 0) {
		printf("Not found.\n");
	}
	else {
		printf("%s,%d\n", st[i].name, st[i].score);
	}
		printf("%d\n", count);
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
