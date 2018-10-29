#include <stdio.h>
char buf[128];

void update(int *p, int i){
	*p += i;
	if(*p >= 100){
		*p = 0;
	}else if(*p <= -100){
		*p = 0;
	}
	return ;
}

int main(){
	int x = 0,i;
	while(fgets(buf,sizeof(buf),stdin) != NULL){
		sscanf(buf,"%d",&i);
		update(&x,i);
		printf("%d\n",x);
	}
	return 0;
}
