#define _CRT_SECURE_NO_WARNINGS
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SETMAX 10600
char buf[256];

struct station {
    int eki;
    char name[64];
    char rosen[64];
}

int
main()
{
    int i = 0;
    int ekisize;
    int l;
    int r;
    int m;
    struct station* ekidata[SETMAX];
    struct station* st;
    char ekname[64];
    FILE* fp = fopen("./ekisen.txt", "r");
    while (fgets(buf, sizeof(buf), fp) != NULL && i < SETMAX) {
        st = (struct station*)malloc(sizeof(struct station));
        ekidata[i] = st;
        ++i;
    }
    fclose(fp);
    ekisize = i;
    scanf("%[^\n]%+c", ekiname);
    l = 0;
    r = ekisize - 1;
    //ここから二分探索
    while(l<=r){
        //umeru
    }
    if(r<l){//駅名が無い場合
        fprintf(stderr, "%s: 駅名がありません\n", ekiname);
        exit(1);
    }else{//駅名がある場合
        //umeru
    }
}