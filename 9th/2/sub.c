﻿#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static int count = 0;
char kijun;

struct point {
	int x;
	int y;
};

int compare_by(struct point p1, struct point p2) {
	//ここを埋める
	count++;
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

int is_heap(struct point a[], int n) {
	//printf("n = %d\n",n);
	int result;
	for (int i = 0;2 * i < n - 1;i++) {
		//printf("i = %d, 2*i+1 = %d, 2*i+2 = %d\n",i,2*i+1,2*i+2);
		// printf("a[%d] = %d %d ",i,a[i].x,a[i].y);
		// printf("a[%d] = %d %d ",2*i+1,a[2*i+1].x,a[2*i+1].y);
		// printf("a[%d] = %d %d\n",2*i+2,a[2*i+2].x,a[2*i+2].y);
		if (compare_by(a[2 * i + 1], a[i]) == 1 && 2 * i + 1 < n) {
			return 0;
		}
		if (compare_by(a[2 * i + 2], a[i]) == 1 && 2 * i + 2 < n) {
			return 0;
		}
	}
	return 1;
}

void pushdown(struct point a[], int m, int n){
	int i;
	struct point temp;
	if(2*m+2<=n){
		if(compare_by(a[2*m+2],a[2*m+1])>=0){
			i = 2*m+2;
		}else{
			i = 2*m+2;
		}
		if(compare_by(a[i],a[m])){
			temp = a[i];
			a[i] = a[m];
			a[m] = temp;
		}
	}
	else if(2*m+1 == n){
		if(compare_by(a[2*m+1],a[m])){
			temp = a[m];
			a[m] = a[2*m+1];
			a[2*m+1] = a[m];
		}
	}
	else if(2*m+1>n){
		;
	}
}

int main() {
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
	pushdown(arr, 0, n - 1);
	printf("%d\n",count);
	for (i = 0;i < n;++i) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}
	return 0;
}