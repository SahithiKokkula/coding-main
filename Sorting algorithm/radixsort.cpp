#include<iostream>
#include<math.h>
using namespace std;
void radix_sort(int arr[],int n){
    int max_ele=INT8_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>max_ele) max_ele=arr[i];
    }
    for(int position=1;max_ele/position>0;position*=10){
    int ans_arr[n];
    int freq[10]={0};
    for(int i=0;i<n;i++){
        freq[(arr[i]/position)%10]++;
    }
    for (int i=1;i<=max_ele;i++){
        freq[i]+=freq[i-1];
    }
    for(int i=n-1;i>=0;i--){
        ans_arr[--freq[(arr[i]/position)%10]]=arr[i];
    }
    for (int i=0;i<n;i++){
        arr[i]=ans_arr[i];
    }
    }
}
int main(){
    int arr[]={916,5461,5,5,61,4,4146,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    radix_sort(arr,n);
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}