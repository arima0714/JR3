#include <stdio.h>
#include <string.h>

struct golden{
	long long int a;
	long long int b;
};

struct golden double_golden(struct golden x){
	struct golden y;
	y.a = x.a * 2;
	y.b = x.b * 2;	
	return y; 
}

int main(){
	struct golden x;
	scanf("%lld %lld",&x.a,&x.b);
	x = double_golden(x);
	printf("%lld %lld\n",x.a, x.b);
	return 0;
}
