#include <stdio.h>
#include <string.h>
#include <math.h>

long long int fib_first = 0;
long long int fib_second = 1;
long long int fib_third = 1;

long long int return_divided(int n){
    long long int a = 0,b = 1,c,i;
    for(i = 0;i <= n; ++i){
	if(i == 0){
		//printf("i = %lld, fib = %lld\n",i,a);
	}else if(i == 1){
		//printf("i = %lld, fib = %lld\n",i,b);
	//}else if(n == i){
	//	return c;

	}else{
		c = a%2018 + b%2018;
		c = c%2018;
		//printf("i = %lld , fib = %lld\n",i,c);
		a = b;
		b = c;
		//printf("i = %d, c = %d\n",i,c);
	}
    }
    return c;
}

int main(void){
	int n;
	scanf("%d",&n);
	printf("%lld\n",return_divided(n));
	return 0;
}
