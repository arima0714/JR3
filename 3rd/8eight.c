#include <stdio.h>
#include <string.h>
#include <math.h>

int fib_first = 0;
int fib_second = 1;
int fib_third = 1;

int return_divided(int n){
	int fib_temp_one = 0;
	int fib_temp_two = 0;
	for(int i = 0;i < n;i++){
		if(n == 0){
			return fib_first;
		}else if(n == 1){
			return fib_second;
		}else if(n == i){
			return fib_third;
		}else{
			fib_temp_one = fib_first;
			fib_temp_two = fib_second;
			fib_first = fib_second;
			fib_second = fib_third;
			fib_third = fib_temp_one + fib_temp_two;	
		}
	}
}

int main(void){
	int n;
	scanf("%d",&n);
	printf("n = %d, fib = %d",n,return_divided(n));
	return 0;
}
