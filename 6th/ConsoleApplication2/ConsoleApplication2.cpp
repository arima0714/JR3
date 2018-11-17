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

#include "pch.h"
#include <stdio.h>
#define DIGITS 126

char buf_one[DIGITS + 2];
char buf_two[DIGITS + 2];
int arr_ans[DIGITS + DIGITS] = {};

void func(char* buf_one, char* buf_two) {

	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	int m = 0;
	int n = 0;
	int o = 0;
	int temp_num = 0;
	int carry = 0;
	static int len_one = 0;
	static int len_two = 0;
	int arr_temp[DIGITS + DIGITS] = {};
	int arr_one[DIGITS + DIGITS] = {};
	int arr_two[DIGITS + DIGITS] = {};
	//数値の桁数を求める
	while (buf_one[len_one] != '\n') {
		++len_one;
	}
	while (buf_two[len_two] != '\n') {
		++len_two;
	}
	//文字列状態の数値を整数型の配列に入れる
	//buf_~~~[len~~~-1-i]を数値にしてarr_~~~に格納
	for (i = 0;i < len_one; ++i) {
		arr_one[i] = (int)(buf_one[len_one - 1 - i] - '0');
	}
	for (j = 0;j < len_two; ++j) {
		arr_two[j] = (int)(buf_two[len_two - 1 - j] - '0');
	}
	for (int l = 0; l < DIGITS;l++) {
		;
	}
	for (l = 0;l < len_one;l++) {
		for (m = 0; m < len_two; m++) {
			temp_num = arr_one[l] * arr_two[m] + carry;
			//計算結果の一桁目をarr_temp[m]に格納
			arr_temp[m] = temp_num % 10;
			temp_num /= 10;
			//計算結果の二桁目をcarryに格納
			carry = temp_num % 10;
		}
		carry = 0;
		//arr_tempの値をarr_ansに入れる
		for (int n = k,o = 0;n < DIGITS + DIGITS;n++, o++) {
			temp_num = arr_ans[n] + arr_temp[o] + carry;
			arr_ans[n] = temp_num % 10;
			temp_num /= 10;
			carry = temp_num % 10;
		}
		k++;
	}

}


int main() {
	//入力される2値を改行まで取得・格納
	//iは答えの桁数
	int i = 0;
	fgets(buf_one, sizeof(buf_one), stdin);
	fgets(buf_two, sizeof(buf_two), stdin);
	func(buf_one, buf_two);
	for (i = DIGITS + DIGITS - 1;i > 0;i--){
		if (arr_ans[i] != 0) {
			break;
		}
	}
	for (;i >= 0;i--) {
		printf("%d", arr_ans[i]);
	}
	printf("\n");
	return 0;
}