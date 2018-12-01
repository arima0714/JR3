#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct point {
	int x;
	int y;
};

struct point_loc {
	int loc;
	struct point p;
};

int compare_by(struct point p1, struct point p2, char c) {
	if (c == 'x') {
		if (p1.x > p2.x) {
			return 1;
		}
		else if (p1.x == p2.x) {
			return 0;
		}
		else {
			return -1;
		}
	}
	else if (c == 'y') {
		if (p1.y > p2.y) {
			return 1;
		}
		else if (p1.y == p2.y) {
			return 0;
		}
		else {
			return -1;
		}
	}
	else {
		int p1_len = p1.x * p1.x + p1.y * p1.y;
		int p2_len = p2.x * p2.x + p2.y * p2.y;
		if (p1_len > p2_len) {
			return 1;
		}
		else if (p1_len == p2_len) {
			return 0;
		}
		else {
			return -1;
		}
	}
}

int max_index_by(struct point_loc a[], int n, char c) {
	int max_i = 0;
	struct point_loc max_p;
	int result = 0;
	max_p = a[0];
	for (int i = 1; i < n; ++i) {
		result = compare_by(a[i].p, max_p.p, c);
		if (result == 1) {
			max_p = a[i];
			max_i = i;
		}
		else if (result == 0) {
			if (a[i].loc > max_p.loc) {
				max_p = a[i];
				max_i = i;
			}
		}
	}
	return max_i;
}

void stable_selection_sort(struct point a[], int n, char c) {
	struct point_loc p_l;
	int j = 0;
	//1. 構造体point_locを要素とする配列arrを用意する．
	struct point_loc arr[128];
	//2. 元の配列aの各要素に適切な添字情報をつけたものをarrに格納する． 
	for (int i = 0; i < n;i++) {
		p_l.p = a[i];
		p_l.loc = i;
		arr[i] = p_l;
	}
	//3. arrを選択ソートアルゴリズムにより整列する(大小比較で等しい場合は添字情報を使用)．
	for (int k = n;k >= 2;k--) {
		j = max_index_by(arr, k, c);
		p_l = arr[j];
		arr[j] = arr[k - 1];
		arr[k - 1] = p_l;
	}
	//4. 整列結果を元の配列aに戻す
	for (int i = 0;i < n;i++) {
		a[i] = arr[i].p;
	}
}

int main()
{
	//printf("hello wordd\n");

	char c;
	char buf[128];
	struct point p;
	struct point arr[128];
	int i = 0;
	int n;
	scanf("%c ", &c);
	while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
		sscanf(buf, "%d %d", &p.x, &p.y);
		arr[i] = p;
		++i;
	}
	n = i;
	stable_selection_sort(arr, n, c);
	for (i = 0;i < n;++i) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
	return 0;
}