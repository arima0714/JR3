#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

struct point {
	int x;
	int y;
};



void radix_sort(struct point a[], int n, int r, int dmax) {
	//for(int i = 0;i<dmax;i++)//桁の移動用（＝０桁目からdmax桁目まで）
	int power = pow(2, r);
	int* hairetu_c;
	for (int i = 0;i < dmax;i++) {
		//2**r個の配列を用意(=バケツソートでのhairetu_c)
		hairetu_c = (int *)malloc(power*(sizeof(int)));
		for (int j = 0;j < dmax;j++) {
			hairetu_c[j] = 0;
		}
		//hairetu_aの先頭から桁をよみ、01での値を10進数化したものをインデクスkとして、hairetu_c[k]++をする
		for (int j = 0;j < n;j++) {
			hairetu_c[((a[j].x >> (i*r))&((1 << r) - 1))]++;
		}
		//for(int i = 1;i<2**r;i++)
		for (int j = 1;j < power;j++) {
			//hairetu_c[i] += hairetu_c[i-1]
			hairetu_c[j] += hairetu_c[j - 1];
		}
		//aと同じ配列hairetu_bを用意
		struct point hairetu_b[128];
		for (int j = 0;j < 128;j++) {
			hairetu_b[j] = a[j];
		}
		//for(i = n-1;i>=0;i--)//１０ページ目の(5)
		for (int j = n - 1;j >= 0;j--) {
			//number = hairetu_b[i]を示された方法で桁を取り出して、それを10進数化したもの
			int number = ((hairetu_b[j].x >> (i*r)) & ((1 << r) - 1));
			//hairetu_c[number]を１減らす
			hairetu_c[number]--;
			//a[hairetu_c[number] = hairetu_b[i]
			a[hairetu_c[number]] = hairetu_b[j];
		}
		for (int j = 0;j < n;j++) {
			printf("%d %d\n", a[j].x, a[j].y);
		}
		printf("--\n");
	}
}

int main() {
	char buf[128];
	struct point p;
	struct point arr[128];
	int i = 0;
	int n;
	int r;
	int dmax;
	scanf("%d %d ", &r, &dmax);

	while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
		sscanf(buf, "%d %d", &p.x, &p.y);
		arr[i] = p;
		++i;
	}
	n = i;
	radix_sort(arr, n, r, dmax);
	return 0;
}