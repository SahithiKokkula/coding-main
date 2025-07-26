#include<stdio.h>
int main(){
    float a,b,c;
    printf("Enter first side: ");
    scanf("%f",&a);
    printf("Enter second side: ");
    scanf("%f",&b);
    printf("Enter third side: ");
    scanf("%f",&c);
    if(a+b>c&&a+c>b&&b+c>a) printf("It can form a Triangle.");
    else printf("Triangle can not be formed.");
    return 0;
}