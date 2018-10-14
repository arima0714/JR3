// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <string.h>

// #define MAXLEN 128
// #define MAXROW 64

// char buf[MAXLEN+2];
// int numbers[MAXROW][MAXLEN];

// void *
// xmaloc(size_t size){
// 	void *p = malloc(size);
// 	return p;
// }

// int main(){

// 	char *p;
// 	int j = 0;
// 	int k = 0;
// 	int row;
// 	// int colum;
// 	int sa = 0;

// 	while(fgets(buf,sizeof(buf),stdin) != NULL){
// 		p = strchr(buf,'\n');
// 		if(p != NULL) *p = '\0';
// 		printf("%s\n",buf);

// 		p = buf;
// 		int i;
// 		while(sscanf(p,"%d",&i) != EOF){
// 			printf("%d\n",i);
// 			numbers[j][k] = i;
// 			p = strchr(p,' ');
// 			if(p == NULL) break;
// 			else while(*p == ' ') ++p;
// 			k++;
// 		}
// 		numbers[j][k] = -1;
// 		j++;
// 	}

// 	row = j;

// 	printf("row = %d",row);

// 	for(int i = 0; i < row; i++){
// 		for(j = 0; ;j++){
// 			if(numbers[i][j] < 0){
// 				break;
// 			}else{
// 				// printf("numbers[%d][%d] = %d\n",i,j,numbers[i][j]);

// 			}
// 		}
// 	}
// 	// p = buf;
// 	// int i;
// 	// while(sscanf(p,"%d",&i) != EOF){
// 	// 	printf("%d\n",i);
// 	// 	p = strchr(p,' ');
// 	// 	if(p == NULL) break;
// 	// 	else while(*p == ' ') ++p;
// 	// }

// }

// 元の状態　-2
// 何か追加されたら　＃
// 空白　-1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAXLEN 128
#define MAXROW 64

char buf[MAXLEN+2];
int numbers[MAXROW][MAXLEN];

void *
xmaloc(size_t size){
	void *p = malloc(size);
	return p;
}

int main(){

	char *p;
	int j = 0;
	// int k = 0;
	int row;
	// int sa = 0;

	for(int row = 0;row < MAXROW;row++){
		for(int colum = 0;colum < MAXLEN;colum++){
			numbers[row][colum] = -2;
		}
	}

	while(fgets(buf,sizeof(buf),stdin) != NULL){
		p = strchr(buf,'\n');
		if(p != NULL) *p = '\0';
		// printf("%s\n",buf);

		p = buf;
		int i;
		// int len = 0;
		while(sscanf(p,"%d",&i) != EOF){
			// printf("%d\n",i);
			numbers[j][i] = i;
			p = strchr(p,' ');
			if(p == NULL) break;
			else while(*p == ' ') ++p;
		}
		numbers[j][i+1] = -1;
		j++;
	}

	row = j;

	// printf("row = %d\n",row);

	for(int i = 0; i < row; i++){
		for(j = 0; ;j++){
			if(numbers[i][j] == -1){
				printf("\n");
				break;
			}else{
				// printf("numbers[%d][%d] = %d\n",i,j,numbers[i][j]);
				if(numbers[i][j] < 0){
					printf(" ");
				}else{
					printf("#");
				}
			}
		}
	}

}