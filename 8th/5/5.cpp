#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char kijun;
int count = 0;

struct point {
	int x;
	int y;
};

int compare_by(struct point p1, struct point p2) {
	++count;
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

int partition(struct point a[], int m, int n) {
	struct point pivot;
	struct point temp;
	struct point temp_one;
	struct point temp_two;
	int l;
	int r;
	pivot = a[m];
	l = m + 1;
	r = n;
	while (1) {
		while (l < n && compare_by(a[l], pivot) == -1) {
			l++;
		}
		while (r > m && compare_by(a[r], pivot) == 1) {
			r--;
		}
		if (l < r) {
			temp = a[l];
			a[l] = a[r];
			a[r] = temp;
		}
		else {
			break;
		}
		l++;
		r--;
	}
	temp_one = a[r];
	temp_two = pivot;
	a[m] = temp_one;
	a[r] = temp_two;
	return r;
}

void quicksort(struct point a[], int m, int n) {
	int p = 0;
	if (m < n) {
		p = partition(a, m, n);
		quicksort(a, m, p - 1);
		quicksort(a, p + 1, n);
	}
	else {
		;
	}
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
	quicksort(arr, 0, n - 1);
	printf("%d\n", count);
	for (i = 0;i < n;++i) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
	return 0;
}