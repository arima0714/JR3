#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
char buf[128];

typedef char datatype;

struct node {

	datatype data;

	struct node *left;

	struct node *right;

};

struct node *get_tree()
{

	struct node *t;

	if (fgets(buf, sizeof(buf), stdin) == NULL || buf[0] == '.') {

		return NULL;

	}

	else {

		t = (struct node *)malloc(sizeof(struct node));

		sscanf(buf, "%c ", &t->data);

		t->left = get_tree();

		t->right = get_tree();

		return t;

	}

}

void print_preorder(struct node *t)
{

	if (t == NULL) {

		;

	}

	else {

		printf("%c", t->data);

		print_preorder(t->left);

		print_preorder(t->right);

	}

}

void print_inorder(struct node *t)
{

	if (t == NULL) {
	} else {

		print_inorder(t->left);

		printf("%c", t->data);

		print_inorder(t->right);
	}

}

void print_postorder(struct node *t)
{

	if (t == NULL) {
	} else {

		print_postorder(t->left);

		print_postorder(t->right);

		printf("%c", t->data);
	}

}

int main()
{

	struct node *t = get_tree();

	print_preorder(t);

	printf("\n");

	print_inorder(t);

	printf("\n");

	print_postorder(t);

	printf("\n");

	return 0;

}

// 繝励Ο繧ｰ繝ｩ繝縺ｮ螳溯｡・ Ctrl + F5 縺ｾ縺溘・ [繝・ヰ繝・げ] > [繝・ヰ繝・げ縺ｪ縺励〒髢句ｧ犠 繝｡繝九Η繝ｼ
// 繝励Ο繧ｰ繝ｩ繝縺ｮ繝・ヰ繝・げ: F5 縺ｾ縺溘・ [繝・ヰ繝・げ] > [繝・ヰ繝・げ縺ｮ髢句ｧ犠 繝｡繝九Η繝ｼ

// 菴懈･ｭ繧帝幕蟋九☆繧九◆繧√・繝偵Φ繝・ 
//    1. 繧ｽ繝ｪ繝･繝ｼ繧ｷ繝ｧ繝ｳ 繧ｨ繧ｯ繧ｹ繝励Ο繝ｼ繝ｩ繝ｼ 繧ｦ繧｣繝ｳ繝峨え繧剃ｽｿ逕ｨ縺励※繝輔ぃ繧､繝ｫ繧定ｿｽ蜉/邂｡逅・＠縺ｾ縺・
//   2. 繝√・繝 繧ｨ繧ｯ繧ｹ繝励Ο繝ｼ繝ｩ繝ｼ 繧ｦ繧｣繝ｳ繝峨え繧剃ｽｿ逕ｨ縺励※繧ｽ繝ｼ繧ｹ邂｡逅・↓謗･邯壹＠縺ｾ縺・//   3. 蜃ｺ蜉帙え繧｣繝ｳ繝峨え繧剃ｽｿ逕ｨ縺励※縲√ン繝ｫ繝牙・蜉帙→縺昴・莉悶・繝｡繝・そ繝ｼ繧ｸ繧定｡ｨ遉ｺ縺励∪縺・//   4. 繧ｨ繝ｩ繝ｼ荳隕ｧ繧ｦ繧｣繝ｳ繝峨え繧剃ｽｿ逕ｨ縺励※繧ｨ繝ｩ繝ｼ繧定｡ｨ遉ｺ縺励∪縺・//   5. [繝励Ο繧ｸ繧ｧ繧ｯ繝・ > [譁ｰ縺励＞鬆・岼縺ｮ霑ｽ蜉] 縺ｨ遘ｻ蜍輔＠縺ｦ譁ｰ縺励＞繧ｳ繝ｼ繝・繝輔ぃ繧､繝ｫ繧剃ｽ懈・縺吶ｋ縺九ー繝励Ο繧ｸ繧ｧ繧ｯ繝・ > [譌｢蟄倥・鬆・岼縺ｮ霑ｽ蜉] 縺ｨ遘ｻ蜍輔＠縺ｦ譌｢蟄倥・繧ｳ繝ｼ繝・繝輔ぃ繧､繝ｫ繧偵・繝ｭ繧ｸ繧ｧ繧ｯ繝医↓霑ｽ蜉縺励∪縺・//   6. 蠕後⊇縺ｩ縺薙・繝励Ο繧ｸ繧ｧ繧ｯ繝医ｒ蜀阪・髢九￥蝣ｴ蜷医ー繝輔ぃ繧､繝ｫ] > [髢九￥] > [繝励Ο繧ｸ繧ｧ繧ｯ繝・ 縺ｨ遘ｻ蜍輔＠縺ｦ .sln 繝輔ぃ繧､繝ｫ繧帝∈謚槭＠縺ｾ縺・