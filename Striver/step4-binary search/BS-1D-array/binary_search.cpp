#include<bits/stdc++.h>
using namespace std;
int searchiterative(vector<int> &nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n-1;

    
    while (left<=right){
        int mid = right - (right - left)/2;
        if(nums[mid]==target) return mid;
        else if (target>nums[mid]){
            left = mid+1;
        }
        else{
            right = mid -1;
        }
    }
    return -1;
}
int searchrecursive(vector<int>nums,int target,int left,int right){
    if (left > right) return -1;
    int mid = right - (right - left)/2;
    if(nums[mid]==target) return mid;
    else if (target>nums[mid]){
        return searchrecursive(nums,target,mid+1,right);
    }
    return searchrecursive(nums,target,left,mid-1);
}

int main(){
    int n;
    cin>>n;
    vector <int> arr;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        arr.emplace_back(num);
    }
    int target;
    cin>>target;
    cout<<searchiterative(arr,target)<<endl;
    cout<<searchrecursive(arr,target,0,n-1);
}