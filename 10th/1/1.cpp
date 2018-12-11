// 1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct student {
	int id;
	char name[32];
	int score;
};

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
	//v は探索すべき得点
	//n は読み込んだ要素数
	// i < n のような添え字による終了判定を行わない

	//(1) n 番めに得点が S であるような構造体 student(番兵という) を入れる．
	st[n].score = v;
	//(2) 配列の i 番めの学生の得点が S と異なる間，i に 1 を足し続ける．
	i = 0;
	while (st[i].score != v) {
		i++;
	}
	//(3) (2) が終わった時点で，i が n であれば得点が S である学生が見つからなかったことになり，i < n で あれば学生の得点が S である最初の学生が i 番めであることを表す．
	if (i == n) {
		printf("Not found.\n");
	}
	else {
		printf("%d,%s", st[i].id, st[i].name);
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
