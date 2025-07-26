#include<iostream>
using namespace std;
void count_sort(int arr[],int n){
    int ans_arr[n];
    int max_ele=INT8_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>max_ele) max_ele=arr[i];
    }
    int freq[max_ele+1]={0};
    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    for (int i=1;i<=max_ele;i++){
        freq[i]+=freq[i-1];
    }
    for(int i=n-1;i>=0;i--){
        ans_arr[--freq[arr[i]]]=arr[i];
    }
    for (int i=0;i<n;i++){
        arr[i]=ans_arr[i];
    }
}
int main(){
    int arr[]={916,5461,5,5,61,4,4146,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    count_sort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}