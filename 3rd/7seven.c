#include <stdio.h>
#include <string.h>
#include <math.h>

int add_number = 0;
int mult_number = 0;

struct golden{
	long long int a;
	long long int b;
};

int size_of_golden(struct golden x, struct golden y){
	long long int R;
	long long int I;
	
	if(x.a == y.a && x.b == y.b){return 0;}

	R = 2 * x.a - 2 * y.a + x.b - y.b;
	I = x.b - y.b;

	if(R > 0 && I >0){return 1;}
	else if(R < 0 && I < 0){return -1;}
	else if(R > 0 && I < 0){
		if(R*R - 5*I*I > 0){
			return 1;					
		}else{
			return -1;
		}
	}else if(R < 0 && I > 0){
		if(R * R - 5 * I * I < 0){
			return -1;
		}else{
			return 1;
		}
	}
}

int main(){
    struct golden one;
    struct golden two;

    scanf("%lld%lld",&one.a,&one.b);
    scanf("%lld%lld",&two.a,&two.b);
	
    printf("%d\n",size_of_golden(one, two));

    return 0;
}
