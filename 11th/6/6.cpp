#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEFT 0
#define RIGHT 1

char buf[128];

struct student {
    int id;
    char name[32];
    int score;
};

typedef struct student datatype;

struct node {
    datatype data;
    struct node* left;
    struct node* right;
};

struct node* get_tree() //ok
{
    struct node* t;
    if (fgets(buf, sizeof(buf), stdin) == NULL || buf[0] == '.') {
        return NULL;
    } else {
        t = (struct node*)malloc(sizeof(struct node));
        sscanf(buf, "%d,%[^,],%d", &t->data.id, t->data.name,
            &t->data.score);
        t->left = get_tree();
        t->right = get_tree();
        return t;
    }
}

void print_node(struct node* t) //ok
{
    if (t == NULL) {
        printf("NULL\n");
    } else {
        printf("%d,%s,%d	printed by print_node()\n", t->data.id, t->data.name, t->data.score);
    }
}

void print_bst(struct node* t) //ok
{
    if (t == NULL) {
        printf(".\n");
    } else {
        printf("%d,%s,%d\n", t->data.id, t->data.name, t->data.score);
        print_bst(t->left);
        print_bst(t->right);
    }
}

struct node* find_id(struct node* t, int id) //ok
{
    struct node* tmp;
    tmp = t;
    while (tmp->data.id != id) {
        if (tmp->data.id < id) {
            tmp = tmp->right;
        } else {
            tmp = tmp->left;
        }
    }
    return tmp;
}

void print_tree(struct node* t) {
	//うめる
	if (t == NULL) {
		printf("-");
	}
	else {
		printf("%d(", t->data.id);
		print_tree(t->left);
		printf(",");
		print_tree(t->right);
		printf(")");
	}
}

struct node* find_id_root(struct node* t, int id)
{
    struct node* tmp;
    tmp = t;
    if (tmp->data.id == id) {
        return NULL;
    } else {
		while (true) {
			if (tmp->left != NULL && tmp->left->data.id == id) {
				break;
			}
			else if (tmp->right != NULL && tmp->right->data.id == id) {
				break;
			}
			if (tmp->data.id < id) {
				tmp = tmp->right;
			}
			else {
				tmp = tmp->left;
			}
        }
        return tmp;
    }
}

struct node* find_min(struct node* t)
{
    struct node* tmp;
    tmp = t;
    tmp = tmp->right;
    while (tmp->left != NULL) {
        tmp = tmp->left;
    }
    return tmp;
}

struct node* find_min_root(struct node* t)
{
    struct node* tmp;
    tmp = t;
    if (tmp->right->left == NULL) {
        return tmp->right;
    } else {
        while (tmp->left->left != NULL) {
            tmp = tmp->left;
        }
    }
    return tmp;
}

//tの指す節点を根とする二分探索木から、学籍番号がidと一致する学生の節点を削除し、得られた二分探索木の根の節点のアドレスを返す関数
struct node* bst_delete(struct node* t, int id)
{
    //struct node* tmp;
    struct node* key; //削除されるノード
    struct node* key_root; //削除されるノードの親
    // struct node* to_be_deleted;//削除されるノード
    struct node* left; //削除されるノードの左側
    struct node* right;//削除されるノードの右側
    struct node* min; //削除されるノードの右側の最小値
    struct node* min_root; //削除されるノードの右側の最小値の根
    //2分探索でkeyを見つける
    key = find_id(t, id);
    //printf("key = ");
    //print_node(key);
    key_root = find_id_root(t, id);
    //printf("key_root = ");
    //print_node(key_root);
    left = key->left;
    right = key->right;
    if (key->right == NULL) {
        //条件１//clear?
    	//printf("one\n");
        //nがあったところに、nの左の子が入る
        if (key_root != NULL) {
            if (key_root->left == key) {
                key_root->left = left;
            } else {
                key_root->right = left;
            }
        }
    } else if (key->right->left == NULL) {
        //条件２
        //printf("two\n");
        //keyの右の子の節点の左の子の節点にkeyの左の子が入る
        key->right->left = key->left;
        //keyの右の子の節点の右の子の節点にkeyの右の子の右の子が入る
        key->right->right = key->right->right;
        //keyがあったところにはkeyの右の子の節点が入る
        if (key_root != NULL) {
            if (key_root->left == key) {
                key_root->left = key->right;
            } else {
                key_root->right = key->right;
            }
        }
    } else {
        //条件３
        //printf("three\n");
        //keyの右側の最小値をminとする
        min = t;
        min = min->right;
        while (min->left != NULL) {
            min = min->left;
        }
        min_root = find_id_root(t, min->data.id);
		//printf("min = ");
		//print_node(min);
        //minの所にminの右の子を入れる
        if (min_root->left == min) {
            min_root->left = min->right;
        } else {
            min_root->right = min->right;
        }
        //keyの所にminを入れる
		min->left = left;
		min->right = right;
        if (key_root != NULL) {
            if (key_root->left == key) {
                key_root->left = min;
            } else {
                key_root->right = min;
            }
        }else{
			t = min;
		}
    }
	free(key);
    return t;
}

int main()
{
    struct node* t = get_tree();
	//print_tree(t);printf("\n");
    int id;
    scanf("%d ", &id);
    t = bst_delete(t, id);
    print_bst(t);
    return 0;
}