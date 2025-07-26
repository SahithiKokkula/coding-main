#include<iostream>
#include<vector>
int main(){
    int n;
    int swap=0;
    std::cin>>n;
    std::vector<int>arr;
    for(int i=0;i<n;i++){
        int ele;
        std::cin>>ele;
        arr.push_back(ele);
    }
    int maxidx=0;
    int minidx=n-1;
    for(int i=0;i<n;i++){
        if(arr[maxidx]<arr[i]) maxidx=i;
    }
    for (int i=maxidx;i>0;i--){
        swap++;
        std::swap(arr[i],arr[i-1]);
    }
    for(int i=n-1;i>0;i--){
        if(arr[minidx]>arr[i]) minidx=i;
    }
    for (int i=minidx;i<n-1;i++){
        swap++;
        std::swap(arr[i],arr[i+1]);
    }
    std::cout<<swap;
}