#include<bits/stdc++.h>
using namespace std;
int findfloor(vector<int> &nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n-1;
    int ans = -1;
    
    while (left<=right){
        int mid = right - (right - left)/2;
        if(nums[mid]==target){
            ans = mid;
            break;
        }
        else if (target>nums[mid]){
            left = mid+1;
            ans = max(mid,ans);
        }
        else{
            right = mid -1;
        }
    }
    return ans;
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
    cout<<findfloor(arr,target);
}