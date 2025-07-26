#include<iostream>
using namespace std;
int partition(int arr[],int first, int last){
    int pivot=arr[last];
    int i=first-1;
    int j=first;
    for(;j<last;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[last]);
    return i+1;
}
void quicksort(int arr[],int first,int last){
    if(last<=first) {
        return;
    }
    int pi=partition(arr,first,last);
    quicksort(arr,first,pi-1);
    quicksort(arr,pi+1,last);
    
}
int main(){
    int arr[]={9,8,7,6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}