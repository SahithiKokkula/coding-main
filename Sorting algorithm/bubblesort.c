#include<stdio.h>
void bubblesort(int arr[], int n){
    for (int i=1;i<n;i++){
        for (int j=0;j<=n-i;j++){
            if(arr[j]>arr[j+1]) {
                int tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
    return;
}
int main(){
    int arr[]={9,8,7,6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    bubblesort(arr,n);
    for (int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    return 0;
}