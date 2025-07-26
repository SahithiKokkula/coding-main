#include<stdio.h>
void sort(int *arr,int n){
    for(int i=1;i<n;i++){
        int curr=arr[i];
        int j=i;
        while(j>0&&curr<arr[j-1]){
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=curr;
    }
}
int main(){
    int arr[]={5,9,3,92,6,1,5,23};
    sort(arr,8);
    for(int i=0;i<8;i++){
        printf("%d ",arr[i]);
    }
}