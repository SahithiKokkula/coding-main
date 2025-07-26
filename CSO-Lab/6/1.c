#include<stdio.h>
int main(){
    int n;
    printf("Enter numbeer of digits to enter in array: ");
    scanf("%d",&n);
    int arr[n];
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The array you entered is : ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}