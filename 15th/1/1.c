#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SETMAX 10600

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

int main()
{
    int n;
    int e;
    struct set s;
    scanf("%d %d ", &n, &e);
    init_set(&s, n, e);
    print_set(&s);
    return 0;
}