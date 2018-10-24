#include <stdio.h>
#include <string.h>

int number = 0;

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
	number += 1;
	struct golden z;
	z.a = x.a * y.a + x.b * y.b;
	z.b = x.a * y.b + y.a * x.b + x.b * y.b;
	return z;
}

struct golden power_golden(struct golden x,int n){
	struct golden z;
	if(n == 0){
		z.a = 1;
		z.b = 0;
	}else if(n%2 == 1){
		z = mult_golden(x,power_golden(x,n-1));
	}else if(n%2 == 0){
		struct golden y;
		y = power_golden(x,n/2);
		z = mult_golden(y,y);

	}
	return z;
}

int main(){
	struct golden x;
	int n;
	scanf("%lld %lld",&x.a,&x.b);
	scanf("%d",&n);	
	x = power_golden(x,n);
	printf("%lld %lld\n",x.a, x.b);
	printf("%d\n",number);
	return 0;
}
