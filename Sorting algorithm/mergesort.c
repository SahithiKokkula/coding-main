#include<stdio.h>
void merge(int arr[],int left,int partition,int right){
    int an=partition-left+1;
    int bn=right-partition;
    int a[an];
    int b[bn];
    int c=0;
    for(int i=left;i<=partition;i++){
        a[c++]=arr[i];
    }
    int d=0;
    for(int i=partition+1;i<=right;i++){
        b[d++]=arr[i];
    }
    int i=0;
    int j=0;
    int k=left;
    while(i<an&&j<bn){
        if(a[i]<b[j]) arr[k++]=a[i++];
        else arr[k++]=b[j++];
    }
    for(i;i<an;i++){
        arr[k++]=a[i];
    }
    for(j;j<bn;j++){
        arr[k++]=a[j];
    }
}
void mergesort(int arr[],int left,int right){
    if(left==right) return;
    int partition=(left+right)/2;
    mergesort(arr,left,partition);
    mergesort(arr,partition+1,right);
    merge(arr,left,partition,right);
}
int main(){
    int arr[]={9,8,7,6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,n-1);
    for (int i=0;i<n;i++){
        printf(" %d",arr[i]);
    }
    return 0;
}