#include<stdio.h>
struct vector1{
    int x,y,z;
};
int main(){
    // char str1[10]="IIT";
    // char *ptr=str1;
    // int a[]={56,58};
    // int *p=a;
    // printf("%d",*p++);
    // printf("%d",a[0]);
    // printf("%s",ptr);
    // int x=4195;int *p=&x; char *c; c=(char*)p; printf("%d",*++c);
//     char *A[4]; A[0]="Hello"; A[1]="IIT"; A[2]="Varanasi"; A[3]="BHU";
// char *p; p=A[0];
// printf("%c %c",*(++p),++A[0][0]); 
int x=15; const int *p=&x; (*p)++;
printf("%d",x);
}