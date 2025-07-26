#include<stdio.h>
int main(){
    float a,b;
    printf("Enter a and b:");
    scanf("%f %f",&a,&b);
    while(a>=b){
        a=a-b;
    }
    printf("%f",a);
    return 0;
}