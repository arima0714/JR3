#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//char case1 = "abcdefg 12345678";
//char case2 = "The University of Electro-Communications";

int main(){

    int i;
    int fib[100001] = {0,1};
    for (i = 2; i < 100001;++i){
        fib[i] = fib[i - 1] + fib[i - 2];
    }

	char str[1000];
	fgets(str,1000,stdin);
	printf("%s",str);
}
