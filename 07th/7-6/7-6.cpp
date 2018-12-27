#include "pch.h"

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int count = 0;

struct point {
	int x;
	int y;
};

int compare_by(struct point p1, struct point p2, char c) {
	count++;
	//ここを埋める
	if (p1.x == p2.x && p1.y == p2.y) {
		return 0;
	}
	else if (c == 'X') {//Xの処理
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
	else if (c == 'Y') {//Yの処理
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

int max_index_by(struct point a[], int n, char c) {
	int max_i = 0;
	struct point max_p;
	int result = 0;
	max_p = a[0];
	for (int i = 1;i < n;++i) {
		result = compare_by(a[i], max_p, c);
		if (result == 1) {
			max_p = a[i];
			max_i = i;
		}
		else if (result == 0) {
			max_p = a[i];
			max_i = i;
		}
	}
	return max_i;
}

void bubble_sort(struct point a[], int n, char c) {
	struct point tmp;
	int result;
	for (int k = n - 2;k >= 0;k--) {
		for (int l = 0;l <= k;l++) {
			struct point a_l = a[l];
			struct point a_l_plus_one = a[l + 1];
			result = compare_by(a[l], a[l + 1], c);
			if (result != -1) {
				tmp = a[l];
				a[l] = a[l + 1];
				a[l + 1] = tmp;
			}
		}
	}
}

int main()
{
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
	bubble_sort(arr, n, c);
	printf("%d\n", count);
	for (i = 0;i < n;++i) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
	return 0;
}