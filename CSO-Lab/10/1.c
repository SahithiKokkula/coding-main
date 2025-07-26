#include<stdio.h>
void swap(int *ptr1,int *ptr2){
    int t=*ptr2;
    *ptr2=*ptr1;
    *ptr1=t;
}
int main(){
    int n1,n2;
    printf("Enter two numbers: ");
    scanf("%d %d",&n1,&n2);
    printf("Before Swapping: %d %d",n1,n2);
    swap(&n1,&n2);
    printf("After Swapping: %d %d",n1,n2);
    return 0;
}
