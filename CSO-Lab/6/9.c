#include<stdio.h>
int main(){
    int n;
    printf("Enter number of digits to enter in array: ");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter number to find the index of: ");
    int num;
    scanf("%d",&num);
    int idx=0;
    for(int i=0;i<n;i++){
        if(arr[i]==num){
            idx=i;
            break;
        }
    }
    printf("Index of the entered element is: %d",idx);
    return 0;
}