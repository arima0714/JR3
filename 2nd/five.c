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
	int row;

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
		int i = 0;
		while(sscanf(p,"%d",&i) != EOF){
			// printf("%d\n",i);
			numbers[j][i] = i;
			p = strchr(p,' ');
			if(p == NULL) break;
			else while(*p == ' ') ++p;
		}
		// printf("\n%d\n",i);
		numbers[j][i] = -3;
		j++;
	}

	row = j;

	// printf("row = %d\n",row);

	for(int i = 0; i < row; i++){
		for(j = 0; ;j++){
			// printf("numbers[%d][%d] = %d\n",i,j,numbers[i][j]);
			if(numbers[i][j] == -3){
				// printf("#\n");
				// break;
				if(j == 0){
					printf("\n");
					break;
				}else{
					printf("#\n");
					break;
				}
			}else if(numbers[i][j] >= 0){
				printf("#");
			}else{
				printf(" ");
			}
		}
	}

}
