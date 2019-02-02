#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SETMAX 10600

char buf[256];
int dist[SETMAX] = { 81, 52, 46, 80, 31, 67, 56, 31, 38, 40 };

struct set {
    int elements[SETMAX];
    int size;
};

void init_set(struct set* p, int n, int e)
{
    int j= 0;
    int i= 0;
    p->size = n - 1;
    while(i < n){
        if(i != e){
            p->elements[j] = i;
            j++;
        }
        i++;
    }
}

void print_set(struct set* p)
{
    int i;
    printf("{");
    for (i = 0; i < p->size; ++i) {
        printf(" %d", p->elements[i]);
    }
    printf(" }\n");
}

int delete_min_int(struct set* p)
{
    int min;
    int i = 0;
    int answer;
    if (p->size == 0) { //1
        return -1;
    } else { //2
        min = p->elements[0];
        for (int j = 0; j <= p->size - 1; j++) {
            if (min > p->elements[j]) {
                min = p->elements[j];
                i = j;
            }
        }
        answer = min;
        p->elements[i] = p->elements[p->size - 1];
        p->size--;
    }
    return answer;
}

int delete_min(struct set* p)
{
    if (p->size == 0) {
        return -1;
    } else {
        int min, min_soeji = 0;
        for (int i = 0; i < p->size; i++) {
            if (dist[p->elements[min_soeji]] > dist[p->elements[i]]) {
                min_soeji = i;
            }
        }
        min = p->elements[min_soeji];
        p->elements[min_soeji] = p->elements[p->size - 1];
        p->size--;
        return min;
    }
}

int main()
{
    int i;
    int m;
    struct set s;
    i = 0;
    while(fgets(buf,sizeof(buf),stdin)!=NULL){
        sscanf(buf, "%d ", &s.elements[i]);
        ++i;
    }
    s.size = i;
    while(true){
        m = delete_min(&s);
        if(m<0){
            break;
        }
        printf("%d : ", m);
        print_set(&s);
    }
    return 0;
}