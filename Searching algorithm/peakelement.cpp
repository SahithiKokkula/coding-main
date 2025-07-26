#include<iostream>
#include<vector>
using namespace std;
int peakele(vector<int>&arr){
    int l=0;
    int h=arr.size()-1;
    int ans=-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(arr[mid]>=arr[mid-1]){
            ans=mid;
            l=mid+1;
        }
        else h=mid-1;
    }
    return arr[ans];
}
int main(){
    vector<int> arr={2,3,4,5,7,8,8,9,6,5,3,1};
    cout<<peakele(arr);
    return 0;
}