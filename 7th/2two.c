#include <stdio.h>

struct point {
	int x;
	int y;
};

int compare_by(struct point p1, struct point p2, char c){
	//ここを埋める
	if(c == 'X'){
		printf("X\n");
		if(p1.x == p2.x && p1.y == p2.y){
			return 0;
		}
		else if(p1.x > p2.x){
			return 1;
		}else if(p1.x == p2.x){
			if(p1.y > p1.y){
				return 1;
			}else{
				return -1;
			}
		}else{
			return -1;
		}
	}else if(c == 'Y'){
		printf("Y\n");
		if(p1.x == p2.x && p1.y == p2.y){
			return 0;
		}
		else if(p1.y > p2.y){
			return 1;
		}else if(p1.y == p2.y){
			if(p1.x > p2.x){
				return 1;
			}else{
				return -1;
			}
		}else{
			return -1;
		}
	}else{
		printf("D\n");
		if(p1.x == p2.x && p1.y == p2.y){
			return 0;
		}
		else if(p1.x * p1.x + p1.y * p1.y > p2.x * p2.x + p2.y * p2.y){
			return 1;
		}
		else if(p2.x * p2.x + p2.y * p2.y > p1.x * p1.x + p1.y * p1.y){
			return -1;
		}
		else if(p1.x > p2.x){
			return 1;
		}
		else if(p2.x > p1.x){
			return -1;
		}
		else if(p1.y > p2.y){
			return 1;
		}
		else{
			return -1;
		}
	}
}

int max_index_by(struct point a[], int n, char c){
	int i = 0;
	int max_i = i;
	struct point max_p;
	max_p = a[i];
	i++;
	for(;i < n;i++){
		if(compare_by(a[i] , max_p, c)){
				max_p = a[i];
				max_i = i;
		}
	}	
	return max_i;
}

int main(){
	char c;
	char buf[128];
	struct point p;
	struct point arr[128];
	int i = 0;
	scanf("%c",&c);
	while(fgets(buf,sizeof(buf),stdin) != NULL && i < 128){
		sscanf(buf,"%d %d",&p.x, &p.y);
		arr[i] = p;
		++i;
	}
	printf("%d\n",max_index_by(arr,i,c));
	return 0;
}

