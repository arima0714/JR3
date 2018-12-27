//// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。

//// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
//// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

//// 作業を開始するためのヒント: 
////    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
////   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
////   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
////   4. エラー一覧ウィンドウを使用してエラーを表示します
////   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
////   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します

//#include "pch.h"
#include <stdio.h>
#define DIGITS 126

char buf_one[DIGITS + 2];
char buf_two[DIGITS + 2];

int main() {
	//使用する変数などの宣言
	int i;
	int j;
	int k;
	int carry;
	int num;
	int len_one;
	int len_two;
	int len_three;
	int arr_one[DIGITS] = {};
	int arr_two[DIGITS] = {};
	int arr_three[DIGITS+1] = {};
	//初期化
	i = 0;
	j = 0;
	k = 0;
	carry = 0;
	//入力される2値を改行まで取得・格納
	fgets(buf_one, sizeof(buf_one), stdin);
	fgets(buf_two, sizeof(buf_two), stdin);
	//それぞれのbufの改行の位置を探し、入力の長さを判断する
	while (buf_one[i] != '\n') {
		++i;
	}
	while (buf_two[j] != '\n') {
		++j;
	}
	//改行の位置をそれぞれのlenに格納
	len_one = i;
	len_two = j;
	//buf_~~~[len~~~-1-i]を数値にしてarr_~~~に格納
	for (i = 0;i < len_one; ++i) {
		arr_one[i] = (int)(buf_one[len_one - 1 - i] - '0');
	}
	for (j = 0;j < len_two; ++j) {
		arr_two[j] = (int)(buf_two[len_two - 1 - j] - '0');
	}
	//printf("\n//arr_~~~[i]の数値を上の位から表示\n");
	////arr_~~~[i]の数値を上の位から表示
	//for (i = len_one - 1;i >= 0;--i) {
	//	printf("%d", arr_one[i]);
	//}printf("\n");
	//for (j = len_two - 1;j >= 0;--j) {
	//	printf("%d", arr_two[j]);
	//}printf("\n");
	for (i = DIGITS - 1; i > len_one; i--) {
		arr_one[i] = 0;
	}
	for (j = DIGITS - 1; j > len_two; j--) {
		arr_two[j] = 0;
	}
	i = 0;
	j = 0;
	while (i < len_one || j < len_two) {
		int tempi = 0;
		int tempj = 0;
		int tempi_j = 0;
		tempi = arr_one[k];
		tempj = arr_two[k];
		tempi_j = tempi + tempj + carry;
		if (tempi_j >= 10) {
			tempi_j = tempi_j - 10;
			carry = 1;
		}
		else {
			carry = 0;
		}
		arr_three[k] = tempi_j;
		++i;
		++j;
		++k;
		/*printf("%d", tempi_j);*/
	}
	if (carry == 1) {
		arr_three[k] = 1;
	}
	else {
		k = k - 1;
	}
	for (;k >= 0;k--) {
		printf("%d", arr_three[k]);
	}
	printf("\n");
	//printf("\n//arr_~~~[i]の数値を下の位から表示\n");
	////arr_~~~[i]の数値を下の位から表示
	//for (i = 0; i <= len_one - 1;++i) {
	//	printf("%d", arr_one[i]);
	//}printf("\n");
	//for (j = 0; j <= len_two - 1;++j) {
	//	printf("%d", arr_two[j]);
	//}printf("\n");


	return 0;
}
