#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct point {
	int x;
	int y;
};

void bucket_sort(struct point a[], int n) {
	//もともとの順番を崩さないようにする
	//並び替え方法は x の値で昇順
	// 0 <= x <= 99 の範囲で x が与えられる
	//printf("n = %d\n", n);
	int i;
	//9ページ目の(1)
	int hairetu_c[100] = {};
	//10ページ目の(2)
	for (i = 0;i < n;i++) {
		hairetu_c[a[i].x]++;
	}
	//10ページ目の(3)
	for (i = 1;i < 100;i++) {
		hairetu_c[i] += hairetu_c[i - 1];
	}
	//10ページ目の(4)
	struct point hairetu_b[128];
	for (i = 0;i < 128;i++) {
		hairetu_b[i] = a[i];
	}
	//10ページ目の(5)
	for (i = n-1;i >= 0;--i) {
		hairetu_c[hairetu_b[i].x]--;
		a[hairetu_c[i]] = hairetu_b[i];
	}
}

int main() {
	char buf[128];
	struct point p;
	struct point arr[128];
	int i = 0;
	int n;
	while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
		sscanf(buf, "%d %d", &p.x, &p.y);
		arr[i] = p;
		++i;
	}
	n = i;
	bucket_sort(arr, n);
	for (i = 0;i < n;++i) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
	return 0;
}