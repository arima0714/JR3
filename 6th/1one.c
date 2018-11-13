#include <stdio.h>
#define DIGITS 126
char buf_one[DIGITS+2];
char buf_two[DIGITS+2];

int main(){
	int i;
	int j;
	int k;
	int num;
	int len_one;
	int len_two;
	int len_three;
	int arr_one[DIGITS] = {};
	int arr_two[DIGITS] = {};
	int arr_three[DIGITS] = {};
	i = 0;
	j = 0;
	k = 0;
	fgets(buf_one,sizeof(buf_one),stdin);
	fgets(buf_two,sizeof(buf_two),stdin);
	while(buf_one[i] != '\n') {
		++i;
	}
	while(buf_two[j] != '\n'){
		++j;
	}
	len_one = i;
	len_two = j;
	for(i = 0;i < len_one; ++i){
		arr_one[i] = (int)(buf_one[len_one-1-i]-'0');
	}
	for(j = 0;j < len_two; ++j){
		arr_two[j] = (int)(buf_two[len_two-1-j]-'0');
	}
	for(i=len_one-1;i>=0;--i){
		printf("%d",arr_one[i]);
	}printf("\n");
	for(j=len_two-1;j>=0;--j){
		printf("%d",arr_two[j]);
	}printf("\n");

	i = len_one;
	j = len_two;
	
	printf("i = %d, j = %d\n",i,j);

	for(i = 0;i < DIGITS;i++){
		printf("i = %d\n    %d\n",i,arr_one);
	}
	
	//桁数の大きい方をarr_threeに写し、kに大きい方の桁を入れている
	//if(i <= j){
	//	//arr_three = arr_two
	//	for(num = 0;num < DIGITS;num++){
	//		arr_three[num] = arr_two[num];
	//	}
	//	k = j;
	//}else{
	//	//arr_three = arr_one
	//	for(num = 0;num < DIGITS;num++){
	//		arr_three[num] = arr_one[num];
	//	}
	//	k = i;
	//}

	

	return 0;
}
