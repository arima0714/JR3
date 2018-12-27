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

struct golden add_golden(struct golden x, struct golden y){
	struct golden z;
	z.a = x.a + y.a;
	z.b = x.b + y.b;
	return z;
}

struct golden mult_golden(struct golden x, struct golden y){
	struct golden z;
	z.a = x.a * y.a + x.b * y.b;
	z.b = x.a * y.b + y.a * x.b + x.b * y.b;
	return z;
}

int main(){
	struct golden x, y;
	scanf("%lld %lld",&x.a,&x.b);
	scanf("%lld %lld",&y.a,&y.b);
	x = mult_golden(x,y);
	printf("%lld %lld\n",x.a, x.b);
	return 0;
}
