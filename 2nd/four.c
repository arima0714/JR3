#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//char case1 = "abcdefg 12345678";
//char case2 = "The University of Electro-Communications";

int main(){

    int i;
    int j;
    int num_of_strings;
    int prime_numbers[1001];
    int prime[11] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };
    for (i = 0; i < 1001; i++) {
        prime_numbers[i] = i;
    }
    for (j = 0; j < 11; j++){
        for (i = 0; i <= 1001; i++){
            if(i % prime[j] == 0 && prime[j] != i){
                prime_numbers[i] = -1;
            }else if(prime_numbers[j] == 1){
                prime_numbers[i] = -1;
            }
        }
    }

    char str[1000];
    char* bf;
    bf = str;
    fgets(str, 1000, stdin);

    for(num_of_strings = 0; str[num_of_strings] != '\0'; ++num_of_strings){
    }
    num_of_strings--;

    // for(i = 0 ; i < num_of_strings; i++){
    //     if(prime_numbers[i] != -1){
    //         printf("%c", str[prime_numbers[i-1]]);
    //     }
    // }

    for(i = 0; i <= num_of_strings; i++){
        if(prime_numbers[i] != -1){
            printf("%c",str[prime_numbers[i]-1]);
        }
    }



    printf("\n");
}
