#include<iostream>
#include<vector>
using namespace std;
void bubble_sort_optimised(vector<float>&arr){
    for (int i=1;i<arr.size();i++){
        int c=0;
        for (int j=0;j<arr.size()-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                c++;
            }
        }
        if(c==0) break;
    }
}
void bucket_sort(float arr[],int n){
    vector<vector<float>> temp(n,vector<float>());
    for(int i=0;i<n;i++){
        int idx=arr[i]*n;
        temp[idx].push_back(arr[i]);

    }
    for(int i=0;i<n;i++){
        if(temp[i].size()!=0) bubble_sort_optimised(temp[i]);
    }
    int k=0;
    for(int i=0;i<n;i++){
        for (int j=0;j<temp[i].size();j++){
            arr[k++]=temp[i][j];
        }
    }
}
int main(){
    float arr[]={.23,.56,.95,.86,.35,.94,.35,.12,.03};
    int n=sizeof(arr)/sizeof(arr[0]);
    bucket_sort(arr,n);
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}