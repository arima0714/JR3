#include <stdio.h>

int max_index(int a[], int n){
	//ここをうめる
	int max;
	int max_i;
	int i = 0;
	max = a[i];
	max_i = i;
	for(;i < n;i++){
		if(max <= a[i]){
			max = a[i];
			max_i = i;
		}
	}
	return max_i;	
}

int main(){
	char buf[128];
	int arr[128];
	int i = 0;
	while(fgets(buf,sizeof(buf),stdin) != NULL && i<128){
		sscanf(buf,"%d",&arr[i++]);
	}
	printf("%d\n",max_index(arr, i));
	return 0;
}
