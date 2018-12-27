#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    char str[1000];
    char *bf;
    int num_of_strings;

    bf = str;
    fgets(str, 1000, stdin);

    for(num_of_strings = 0; str[num_of_strings] != '\0'; ++num_of_strings){
        if(str[num_of_strings] == '/' && str[num_of_strings + 1] == '/'){
            num_of_strings++;
            break;
        }
    }
    num_of_strings--;

    printf("%d\n",num_of_strings);
}