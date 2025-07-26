#include<stdio.h>
int main(){
    int a=1,b=1;
    int c=a+b;
    int n;
    printf("Enter number of terms:");
    scanf("%d",&n);
    if(n==1) printf("%d ",a);
    else if(n==2) printf("%d %d",a,b);
    else{
        printf("%d %d ",a,b);
        for(int i=3;i<=n;i++){
            printf("%d ",c);
            a=b;
            b=c;
            c=a+b;
        }
    }
    return 0;
}