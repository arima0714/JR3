#include <stdio.h>


static int map[1000][1000];

int nck(int first, int second){
    if(second == 0 || first == second){
        return 1;
    }else if(0 < second && second < first){
        return map[first - 1][second]%2018 + map[first - 1][second - 1]%2018;
    }else{
        return 0;
    }
}

int main(void){
    int first;
    int second;
    scanf("%d %d", &first, &second);

    for (int i = 0; i < 1000; i++){
        for (int j = 0; j < 1000; j++) {
            map[i][j] = nck(i, j);
        }
    }

        // printf("%d\n", nck(first, second)%2018);
        printf("%d\n", map[first][second]%2018);
}