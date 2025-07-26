#include<bits/stdc++.h>
using namespace std;
int findPeakElement(vector<int>nums){
    int n = nums.size();
    if (n==1) return 0;
    if (nums[0]>nums[1]) return 0;
    if (nums[n-1]>nums[n-2]) return n-1;
    int left = 1;
    int right = n-2;
    int mid;
    while (left <= right){
        mid = right - (right -left)/2;
        if (nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
            return mid;
        }
        else if (nums[mid]<nums[mid-1]){
            left = mid +1;
        }
        else {
            right  = mid-1;
        }
    }
    return -1;
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
    cout<<findPeakElement(arr);
    return 0;
}