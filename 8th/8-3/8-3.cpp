#include "pch.h"
#include <stdio.h>
#include <stdbool.h>

int count = 0;
char kijun;
struct point {
	int x;
	int y;
};

int compare_by(struct point p1, struct point p2) {
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
	struct point tmp[128];
	before = m;
	after = h+1;
	i = 0;
	while(true){
//		beforeがh以下 かつ afterがn以下 の場合
//			a[before] と a[after] で大きい方を tmp[i] にいれる
//			入れた方の before もしくは after を1加算
//		beforeがh以下の場合
//			a[before] を tmp[i] にいれる
//			before を1加算
//		afterがn以下の場合
//			a[after] を tmp[i] にいれる
//			after を1加算
//		上の３条件を満たさない時(= else)
//			break
	}

//	並べ終えた tmp[] を a[] に入れ直す
}

int main() {
	char buf[128];
	struct point p;
	struct point arr[128];
	int i = 0;
	int h;
	int n;
	scanf("%c %d ", &kijun, &h);
	while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
		sscanf(buf, "%d %d", &p.x, &p.y);
		arr[i] = p;
		++i;
	}
	n = i;
	merge(arr, 0, n - 1, h);
	printf("%d\n", count);
	for (i = 0;i < n;++i) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
	return 0;
}