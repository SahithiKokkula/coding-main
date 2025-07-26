#include<stdio.h>
int main(){
    int n;
    printf("Enter number of digits to enter in array: ");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int max=arr[0],min=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max) max=arr[i];
        if(arr[i]<min) min=arr[i];
    }
    printf("Minimum = %d \nMaximum = %d",min,max);
    return 0;
}