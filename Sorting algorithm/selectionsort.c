#include<stdio.h>
void selectionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min_idx]){
                min_idx=j;
            }
        }
        if(min_idx!=i){
            int tmp=arr[min_idx];
            arr[min_idx]=arr[i];
            arr[i]=tmp;
        }
    }
    return;
}
int main(){
    int n;
    printf("Enter size of array");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    selectionsort(arr,n);
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}