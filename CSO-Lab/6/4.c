#include<stdio.h>
int main(){
    int n;
    printf("Enter number of digits to enter in array: ");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>max) max=arr[i];
    }
    int freq[max+1];
    for(int i=0;i<max+1;i++){
        freq[i]=0;
    }
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    for(int i=0;i<max+1;i++){
        if(freq[i]!=0)
        printf("The freq of element %d is %d\n",i,freq[i]);
    }
    return 0;
}