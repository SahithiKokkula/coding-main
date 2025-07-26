#include<stdio.h>
int main(){
    int a,n,d;
    printf("Enter a, n, d in the respective order: ");
    scanf("%d %d %d",&a,&n,&d);
    printf("Sum of AP: %d",n*(2*a+(n-1)*d)/2);
    return 0;
}