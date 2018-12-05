#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct point {
	int x;
	int y;
};

void radix_sort(struct point a[], int n, int r, int dmax) {

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