#include<stdio.h>
int arrange_array(int *arr,int n){
    int i=0,j=n-1;
    while(i<=j){
        while (arr[i] < 0 && i <= j) {
            i++;
        }
        while (arr[j] > 0 && i <= j) {
            j--;
        }
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    arrange_array(arr,n);
    
    return 0;
}