#include<stdio.h>
int fact(int n){
    if(n==0) return 1;
    return n*fact(n-1);
}
int main(){
    printf("Enter the number: ");
    int n;
    scanf("%d",&n);
    printf("Factorial of %d is: %d",n,fact(n));
    return 0;
}