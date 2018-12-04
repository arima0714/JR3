#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int count = 0;
char kijun;
struct point { int x, y; };

int compare(struct point p1, struct point p2) {
	count++;
	if (kijun == 'X') {
		if (p1.x > p2.x) {
			return 1;
		}
		else if (p1.x == p2.x) {
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
			return -1;
		}
	}
	else if (kijun == 'Y') {
		if (p1.y > p2.y) {
			return 1;
		}
		else if (p1.y == p2.y) {
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
		else {
			return -1;
		}
	}
	else if (kijun == 'D') {
		if (((p1.x)*(p1.x) + (p1.y)*(p1.y)) > ((p2.x)*(p2.x) + (p2.y)*(p2.y))) {
			return 1;
		}
		else if (((p1.x)*(p1.x) + (p1.y)*(p1.y)) == ((p2.x)*(p2.x) + (p2.y)*(p2.y))) {
			if (p1.x > p2.x) {
				return 1;
			}
			else if (p1.x == p2.x) {
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
				return -1;
			}
		}
		else {
			return -1;
		}
	}

}

//m+1からnがヒープになってるときm番めを適切な位置に挿入して
//m番めからn番めがヒープになるような関数
void pushdown(struct point a[], int m, int n) {
	int i, k;
	struct point t;
	printf("2*m+2 = %d, n = %d\n", 2 * m + 2, n);
	if (2 * m + 2 <= n) {
		k = compare(a[2 * m + 1], a[2 * m + 2]);
		if (k == 1) i = 2 * m + 1;
		else i = 2 * m + 2;

		if (compare(a[i], a[m]) == 1) {
			t = a[i]; a[i] = a[m]; a[m] = t;
			pushdown(a, i, n);
		}
	}
	else if (2 * m + 1 == n) {
		if (compare(a[2 * m + 1], a[m]) == 1) {
			t = a[2 * m + 1]; a[2 * m + 1] = a[m]; a[m] = t;
		}
	}

}

int main() {
	char buf[128];
	struct point p, arr[128];
	int i = 0, n;

	scanf("%c ", &kijun);
	while (fgets(buf, sizeof(buf), stdin) != NULL && i < 128) {
		sscanf(buf, "%d %d", &p.x, &p.y);
		arr[i] = p;
		i++;
	}
	//nは要素数
	n = i;

	pushdown(arr, 0, n - 1);
	printf("%d\n", count);
	for (i = 0; i < n; i++) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}

	return 0;
}