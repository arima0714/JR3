#include <stdio.h>
#include <string.h>
#include <math.h>

int add_number = 0;
int mult_number = 0;

struct golden{
	long long int a;
	long long int b;
};

// struct golden double_golden(struct golden x){
// 	struct golden y;
// 	y.a = x.a * 2;
// 	y.b = x.b * 2;	
// 	return y; 
// }

// struct golden add_golden(struct golden x, struct golden y){
// 	struct golden z;
// 	z.a = x.a + y.a;
// 	z.b = x.b + y.b;
// 	return z;
// }

struct golden mult_golden(struct golden x, struct golden y){
	struct golden z;
	z.a = x.a * y.a + x.b * y.b;
	z.b = x.a * y.b + y.a * x.b + x.b * y.b;
	add_number += 3;
	mult_number += 5;
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

float size_of_golden(struct golden x){
    float root_five = pow(5,0.5);
    float phi = (1+root_five)/2;
    return x.a + x.b * phi;
}

int main(){
    struct golden one;
    struct golden two;

    scanf("%lld%lld",&one.a,&one.b);
    scanf("%lld%lld",&two.a,&two.b);
	
    if(size_of_golden(one) > size_of_golden(two)){
        printf("1\n");
    }else if(size_of_golden(one) < size_of_golden(two)){
        printf("-1\n");
    }else{
        printf("0\n");
    }
}
