#include <stdio.h>

int main(void){
	int a[10];
	int one,two;

	scanf("%d %d %d %d %d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9]);

	if(a[0] >= a[1]){
		one = a[0];
		two = a[1];
	}else{
		one = a[1];
		two = a[0];
	}

	for(int i = 2; i < 10 ; i++){
	
		if(two < a[i] && one >= a[i]){
			two = a[i];
		}else if(one <= a[i]){
			two = one;
			one = a[i];
		}
	}

	printf("%d\n",two);
}

