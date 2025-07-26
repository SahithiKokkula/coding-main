#include<stdio.h>
int sumArray(int *ptr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=*ptr;
        ptr++;
    }
    return sum;
}
int main(){
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("%d",sumArray(&arr,n));
    return 0;
}