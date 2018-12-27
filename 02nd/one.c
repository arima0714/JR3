#include <stdio.h>

int main(void){
    int i;
    int fib[100001] = {0,1};
    int num;
    for (i = 2; i < 100001;++i){
        fib[i] = fib[i - 1]%2018 + fib[i - 2]%2018;
    }

    scanf("%d", &num);

    printf("%d\n", fib[num]%2018);
}