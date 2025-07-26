#include<stdio.h>
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    for(int i=1;i<=a;i++){
        if(b*i>a){
            printf("a/b=%d",i-1);
            break;
        }
    }
}