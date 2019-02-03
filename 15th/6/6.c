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
};

int main()
{
    int i = 0;
    int ekisize;
    int l;
    //データの最後のインデックス
    int r;
    int m;
    //二分探索において先頭のインデックス
    int first;
    //二分探索において最後のインデックス
    int last;
    int center;
    struct station* center_eki;
    struct station* ekidata[SETMAX];
    struct station* st;
    char ekiname[64];
    FILE* fp = fopen("./ekisen.txt", "r");
    while (fgets(buf, sizeof(buf), fp) != NULL && i < SETMAX) {
        st = (struct station*)malloc(sizeof(struct station));
        sscanf(buf, "%[^:]:%d:%[^\n]*c", st->name, &st->eki, st->rosen);
        ekidata[i] = st;
        ++i;
    }
    fclose(fp);
    ekisize = i;
    scanf("%[^\n]%*c", ekiname);
    l = 0;
    r = ekisize - 1;
    #ifdef DEBUG
    printf("ekisize = %d\n", ekisize);
    printf("r = %d\n", r);
    printf("l = %d\n", l);
    printf("m = %d\n", m);
    printf("ekidata[%d]: eki = %d,name = %s,rosen = %s\n", 0, ekidata[0]->eki, ekidata[0]->name, ekidata[0]->rosen);
    #endif
    //ここから二分探索
    first = 0;
    last = r;
    while(l<=r){
        //umeru
        center = (last - first)/2 + first;
        #ifdef DEBUG
        printf("center = %d\n", center);
        printf("before ekidata[center]\n");
        #endif
        center_eki = ekidata[center];
        #ifdef DEBUG
        printf("strcmp(%s,%s) = %d\n", ekiname, center_eki->name, strcmp(ekiname, center_eki->name));
        printf("strcmp(%s,%s) = %d\n", center_eki->name, ekiname, strcmp(center_eki->name, ekiname));
        #endif
        if(strcmp(ekiname,ekidata[center]->name) > 0){
            first = center;
            last = last;
        }else if(strcmp(ekiname,ekidata[center]->name) < 0){
            first = first;
            last = center;
        }else{
            //一致
            m = center;
            break;
        }
        l = first;
        r = last;

    }
    if(r<l){//駅名が無い場合
        fprintf(stderr, "%s: 駅名がありません\n", ekiname);
        exit(1);
    }else{//駅名がある場合
        #ifdef DEBUG
        printf("%d\n", strcmp(ekiname, ekidata[center]->name));
        printf("-----ekiname = %s,ekidata[center] = %s------\n",ekiname,ekidata[center]->name);
        printf("strcmp(%s,%s) = %d\n",ekiname,ekidata[center]->name,strcmp(ekiname,ekidata[center]->name));
        #endif
        while(0< center && center < ekisize && strcmp(ekiname,ekidata[center]->name)==0){
            #ifdef DEBUG
            printf("center = %d\nekisize = %d\n", center, ekisize);
            #endif
            if (strcmp(ekiname, ekidata[center-1]->name) == 0){
                center--;
            }else{
                break;
            }
        }
        while(strcmp(ekiname,ekidata[center]->name) == 0){
            printf("%d:%s\n",ekidata[center]->eki, ekidata[center]->rosen);
            center++;
        }
    }
    
    return 0;
}