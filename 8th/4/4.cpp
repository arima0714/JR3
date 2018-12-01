﻿// 4.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int count = 0;
char kijun;

struct point {
	int x;
	int y;
};

int compare_by(struct point p1, struct point p2) {
	count++;
	//ここを埋める
	if (p1.x == p2.x && p1.y == p2.y) {
		return 0;
	}
	else if (kijun == 'X') {//Xの処理
		if (p1.x > p2.x) {
			return 1;
		}
		else if (p1.x < p2.x) {
			return -1;
		}
		else if (p1.y > p2.y) {
			return 1;
		}
		else {
			return -1;
		}
	}
	else if (kijun == 'Y') {//Yの処理
		if (p1.y > p2.y) {
			return 1;
		}
		else if (p1.y < p2.y) {
			return -1;
		}
		else if (p1.x > p2.x) {
			return 1;
		}
		else {
			return -1;
		}
	}
	else {//Dの処理
		int p1xy = p1.x * p1.x + p1.y * p1.y;
		int p2xy = p2.x * p2.x + p2.y * p2.y;
		if (p1xy > p2xy) {
			return 1;
		}
		else if (p1xy < p2xy) {
			return -1;
		}
		else if (p1.x > p2.x) {
			return 1;
		}
		else if (p1.x < p2.x) {
			return -1;
		}
		else if (p1.y > p2.y) {
			return 1;
		}
		else {
			return -1;
		}
	}
}

void merge(struct point a[], int m, int n, int h) {
	//前半の配列はa[m]〜a[h]
	//後半の配列はa[h+1]〜a[n]
	int i;
	int before;
	int after;
	int result = 0;
	struct point tmp[128];
	before = m;
	after = h + 1;
	i = m;
	while (true) {
		//		beforeがh以下 かつ afterがn以下 の場合
		if (before <= h && after <= n) {
			//			a[before] と a[after] で小さい方を tmp[i] にいれる
			//			入れた方の before もしくは after を1加算
			result = compare_by(a[before], a[after]);
			if (result == -1) {
				tmp[i] = a[before];
				before++;
			}
			else if (result == 0) {
				tmp[i] = a[before];
				before++;
			}
			else {
				tmp[i] = a[after];
				after++;
			}
		}
		//		beforeがh以下の場合
		else if (before <= h) {
			//			a[before] を tmp[i] にいれる
			//			before を1加算
			tmp[i] = a[before];
			before++;
		}
		//		afterがn以下の場合
		else if (after <= n) {
			//			a[after] を tmp[i] にいれる
			//			after を1加算
			tmp[i] = a[after];
			after++;
		}
		//		上の３条件を満たさない時(= else)
		else {
			//			break
			break;
		}
		i++;
	}

	//	並べ終えた tmp[] を a[] に入れ直す
	for (int i = m; i <= n;i++) {
		a[i] = tmp[i];
	}
}

void merge_sort(struct point a[], int m, int n) {
	//以下を埋める
	int h;
	//mがnより小さければ以下の手続きを行う
	if (m < n) {
		//	(m + n) / 2 (mとnの平均の小数点以下を切り捨てた値)を前半終了の添字hとする
		h = (m + n) / 2;
		//	配列aのm番めからh番めまでをマージソートにより整列する
		merge_sort(a, m, h);
		//	配列aのh + 1番めからn番めまでをマージソートにより整列する
		merge_sort(a, h + 1, n);
		//	関数mergeにより，配列aのm番めからh番めまでとh + 1番めからn番めまでを併合する
		merge(a, m, n, h);
	}
	////mがn以上なら何もしない(配列のうち長さが1以下の部分の整列であるため)
	//else if (m >= n) {
	//	;
	//}
}

int main()
{
	char buf[128];
	struct point p;
	struct point arr[128];
	int i = 0;
	int n;
	scanf("%c ", &kijun);
	while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
		sscanf(buf, "%d %d", &p.x, &p.y);
		arr[i] = p;
		++i;
	}
	n = i;
	merge_sort(arr, 0, n - 1);
	printf("%d\n", count);
	for (i = 0; i < n; ++i) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
 	return 0;
}