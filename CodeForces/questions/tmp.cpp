#include<iostream>
using namespace std;
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
    int arr[]={0,123,168,714,868,987};
    cout<<binary_search(arr,1,5,424,0);
}