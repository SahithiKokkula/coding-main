#include<stdio.h>
int main(){
    int n;
    printf("Enter number of digits to enter in array: ");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    printf("The sum of array entered is : %d",sum);
    return 0;
}