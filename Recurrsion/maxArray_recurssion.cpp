#include<iostream>
using namespace std;
int a_max(int *arr,int len,int ans = INT8_MIN,int idx=0){
    if(idx==len) return ans;
    if(arr[idx]>ans) ans=arr[idx];
    a_max(arr,len,ans,idx+1);
}
int main(){
    int arr[]={1,2,15,4,8,30};
    int len=sizeof(arr)/sizeof(arr[0]);
    cout<<a_max(arr,len);
}