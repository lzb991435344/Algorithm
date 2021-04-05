#include<stdio.h>


int add_range(int min, int max){
    int sum ;
    for(int i = min; i < max + 1 ; i++){
        sum = sum + i;
    }
    return sum;
}
int main(){
    int range[5];
    range[0] = add_range(1, 10);
    range[1] = add_range(1, 100);
    printf("range[0]=%d\n", range[0]);
    printf("range[1]=%d\n", range[1]);
    return 0;
}