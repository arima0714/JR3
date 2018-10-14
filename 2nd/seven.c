#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){

    char strone[1000];
    char strtwo[1000];

    int j;

    fgets(strone, 1000, stdin);
    fgets(strtwo, 1000, stdin);

    for(int i = 0; strone[i] != '\0';i++){
        j = 0;
        // printf("i = j = %d\n",j);
        while(strone[i+j] == strtwo[j]){
            // printf("strone[i+j] = %c, strtwo[j] = %c, strtwo[j+1] = %c\n",strone[i+j],strtwo[j],strtwo[j+1]);
            if(strtwo[j+2] == '\0'){
                printf("%d\n",i);
                return 0;
            }
            j++;
        }
    }

    // for(int i = 0;strtwo[i] != '\0';i++){
    //     printf("strtwo[i] = %c\n",strtwo[i]);
    // }

    printf("%d\n",-1);
    return 0;
}