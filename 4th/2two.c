#include <stdio.h>
char buf[128];

struct zahyo{
	int x;
	int y;
};

void update(struct zahyo *p,int i,int j){

	return ;

}

int main(){
	struct zahyo xy = {0, 0};
	int i, j;
	while(fgets(buf,sizeof(buf),stdin) != NULL){
		sscanf(buf,"%d %d",&i,&j);
		update(&xy,i,j);
		printf("%d %d\n",xy.x,xy.y);
	}
	return 0;
}
