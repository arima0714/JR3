//#include "pch.h"

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
		else if (p1.x == p2.y) {
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

void stable_selection_sort(struct point a[], int n, char c) {

}
