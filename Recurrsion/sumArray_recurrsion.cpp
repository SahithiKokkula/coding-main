#include<iostream>
using namespace std;
int a_max(int *arr,int len,int ans = 0,int idx=0){
    if(idx==len) return ans;
    ans+=arr[idx];
    a_max(arr,len,ans,idx+1);
}
int main(){
    int arr[]={1};
    int len=sizeof(arr)/sizeof(arr[0]);
    cout<<a_max(arr,len);    
}
