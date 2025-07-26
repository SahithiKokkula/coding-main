#include<bits/stdc++.h>
using namespace std;
//Dutch National flag algorithm
void sortarr(vector<int>nums){
    int low =0;
    int mid = 0;
    int high = nums.size()- 1;
    while(nums[low]==0 && low<=high){
        low++;
    }
    mid=low;
    while(nums[mid]==1 && mid<=high){
        mid++;
    }
    while(nums[high]==2){
        high--;
    }
    while (mid<=high){
        if(nums[mid]==0){
            swap(nums[low++],nums[mid++]);
        }
        else if (nums[mid]==1){
            mid++;
        }
        else{
            swap(nums[high--],nums[mid]);
        }
    }
    return ;
}
int main(){
    int n;
    cin>>n;
    int num;
    vector<int>arr;
    for (int i=0;i<n;i++){
        cin>>num;
        arr[i]=num;
    }
    sortarr(arr);
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}