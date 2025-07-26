#include<stdio.h>
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a==b==c) printf("All are equal");
    else if(a>=b&&a>=c) printf("a is greatest: %d",a);
    else if(b>=a&&b>=c) printf("b is greatest: %d",b);
    else if(c>=b&&c<=a) printf("c is greatest: %d",c);
    return 0;
}
