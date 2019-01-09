// 3.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char buf[128];

struct student {
    int id;
    char name[32];
    int score;
};

typedef struct student datatype;

struct avl_node{
    datatype data;
    struct avl_node *left;
    struct avl_node *right;
    int height;
};

int height(struct avl_node* t) {
	if (t == NULL) {
		return 0;
	}
	else {
		return t->height;
	}
}

//左右の部分木の高さが正しく設定されているときにメンバheightを適切に設定しなおす関数
void put_height(struct avl_node *t) {
	if (t == NULL) {
		return;
	}
	if (t->left != NULL && t->right != NULL) {
		if (height(t->left) > height(t->right)) {
			t->height = height(t->left) + 1;
		}
		else {
			t->height = height(t->right) + 1;
		}
	}
	else if (t->left != NULL) {
		t->height = height(t->left) + 1;
	}
	else {
		t->height = height(t->right) + 1;
	}
}

struct avl_node *get_avl() {
	struct avl_node *t;
	if (fgets(buf, sizeof(buf), stdin) == NULL || buf[0] == '.') {
		return NULL;
	}
	else {
		t = (struct avl_node*)malloc(sizeof(struct avl_node));
		sscanf(buf, "[%d]%d,%[^,],%d", &t->height, &t->data.id, t->data.name, &t->data.score);
		t->left = get_avl();
		t->right = get_avl();
		return t;
	}
}

struct avl_node* rotate_right(struct avl_node *t) {
	struct avl_node* large_a = t;
	struct avl_node* large_b = t->left;
	if (large_b == NULL) {
		return t;
	}
	struct avl_node* tree_one = large_b->left;
	struct avl_node* tree_two = large_b->right;
	struct avl_node* tree_thr = large_a->right;
	large_b->left = tree_one;
	large_b->right = large_a;
	large_a->left = tree_two;
	large_a->right = tree_thr;

	put_height(large_a);
	put_height(large_b);
	return large_b;
}

struct avl_node* rotate_left(struct avl_node *t) {
	struct avl_node* large_b = t;
	struct avl_node* large_a = large_b->right;
	if (large_a == NULL) {
		return t;
	}
	struct avl_node* tree_one = large_b->left;
	struct avl_node* tree_two = large_a->left;
	struct avl_node* tree_thr = large_a->right;
	large_a->left = large_b;
	large_a->right = tree_thr;
	large_b->left = tree_one;
	large_b->right = tree_two;

	put_height(large_b);
	put_height(large_a);
	return large_a;
}

void print_avl(struct avl_node *t){
    if(t == NULL){
        printf(".\n");
    }else{
        printf("[%d]%d,%s,%d\n",t->height,t->data.id,t->data.name,t->data.score);
        print_avl(t->left);
        print_avl(t->right);
    }
}

//構造体avl_nodeのアドレスtの指す接点を根とするAVL木に構造体studentの値dを挿入してAVL木の条件を満たすように調節し、挿入後の根の節点のアドレスを返す関数
struct avl_node* avl_insert(struct avl_node* t, struct student d){
    //tが葉(NULL)かどうか
		//葉なら、節点のメモリを確保し、この節点の左右の部分木を葉とし、データとしてdをいれ高さを1として、この節点のアドレスを返す
		//葉でないならそのデータの学籍番号とdの学籍番号を比較する
			//dの学籍番号のほうが小さければ、左の部分木を「左の部分木にdを挿入した木」で置き換える
			//dの学籍番号のほうが大きければ、右の部分木を「右の部分木にdを挿入した木」で置き換える
	//tの指す接点のメンバheightを適切に更新する
	//挿入によってAVL木の条件を満たさなくなっていたら「balance」を用いてAVL木の条件を満たす形にする
	//根の節点のアドレスを返す

    return t;
}

int main()
{
    struct student st;
    struct avl_node* t = NULL;
    while(fgets(buf,sizeof(buf),stdin)!=NULL){
        sscanf(buf,"%d,%[^,],%d",&st.id,st.name,&st.score);
        t = avl_insert(t,st);
    } 
    print_avl(t);
    return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
