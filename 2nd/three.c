<<<<<<< HEAD
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
=======
#include <stdio.h>

int power(int a, int b){
	int answer  = 1;
	if(b == 0){
		return 1;
	}else{
		for(int i = 0; i < b; i++){
			answer = answer * a;		
		}
	}
	return answer;
}

int ncr(int a, int b){
	if(b == 0){
		return 1;
	}else if(b == 1){
		return a;
	}else if(b%2 == 1){
		return (ncr(a,b-1)%2018 * a%2018)%2018;		
	}else{
		return (ncr(a,b/2)%2018 * ncr(a,b/2)%2018)%2018;
	}
}

int main(){
	int a;
	int b;
	scanf("%d %d",&a,&b);
	printf("%d\n",ncr(a,b));
}
>>>>>>> d4bb919e7c89ee083a15fa8d92a7eedd7eadf993
