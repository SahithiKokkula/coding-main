#include<stdio.h>
int main(){
    int a=0,b=11;
    while(b>>a) {
        printf("%d %d \n",a-1, b>>(a++));
        // printf("%d",a);
    }
}