#include<stdio.h>
#include<math.h>
int main(){
    int n;
    float x;
    printf("Enter degree of polynomial: ");
    scanf("%d",&n);
    int result=0;
    int coeff[n+1];
    for(int i=0;i<=n;i++){
        printf("Enter coeff of x^%d:",i);
        scanf("%d",&coeff[i]);
    }
    printf("Enter value of x: ");
    scanf("%f",&x);
    for(int i=0;i<=n;i++){
        result+=coeff[i]*pow(x,i);
    }
    printf("%d",result);
    return 0;
}