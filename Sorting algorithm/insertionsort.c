#include<stdio.h>
void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int j=i-1;
        while(j>=0&&curr<arr[j]){
            arr[j+1]=arr[j--];
        }
        arr[j+1]=curr;
    }
}
int  main(){
    int arr[]={9,8,498,48,8,49,1};
    int n= sizeof(arr)/sizeof(arr[0]);
    insertionsort(arr,n);
    for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}