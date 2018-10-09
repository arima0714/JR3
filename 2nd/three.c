#include <stdio.h>

int power(int a, int b){
    int answer = 1;
    if(b == 0){
        return 1;
    }else{
        for (int i = 0; i < b; i++){
            answer = answer * a;
        }
        return answer;
    }
}

// calc(int a, int b){
//     if (b % 2 == 0) {

//     }else{

//     }
// }

int main(void){

    int a;
    int b;

    scanf("%d %d", &a, &b);

    printf("%d\n", power(a, b));


}