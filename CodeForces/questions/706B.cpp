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
int binary_search(int arr[],int i,int j,int target,int idx){
    if(i>j) return idx;
    int mid=i+(j-i)/2; //  (r+l)/2
    if(arr[mid]==target) return mid;
    else if(arr[mid]>target){
        binary_search(arr,i,mid-1,target,idx);
    }
    else if(arr[mid]<target){ 
        idx=mid;
        binary_search(arr,mid+1,j,target,idx);
    }
}
int main(){
    int n;
    cin>>n;
    int prices[n];
    for(int i=0;i<n;i++){
        cin>>prices[i];
    }
    int q;
    cin>>q;
    int conins_spent[q];
    for(int i=0;i<q;i++){
        cin>>conins_spent[i];
    }
    quicksort(prices,0,n-1);
    
    int NumberOfShops[q];
    for(int i=0;i<q;i++){
        int number=binary_search(prices,0,n-1,conins_spent[i],-1);
        NumberOfShops[i]=number+1;
    }
    for(int i=0;i<q;i++){
        cout<<NumberOfShops[i]<<endl;
    }
    return 0;
}