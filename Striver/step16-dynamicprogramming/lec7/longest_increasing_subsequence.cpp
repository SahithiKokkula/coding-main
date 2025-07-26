#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int sol1(int idx, int prev_idx, int n, vector<int>&nums){
        if(idx == n) return 0;

        if (prev_idx == -1 || nums[idx] > nums[prev_idx]){
            return max(1 + sol1(idx+1,idx,n,nums),sol1(idx+1,prev_idx,n,nums));
        }
        else{
            return sol1(idx+1,prev_idx,n,nums);
        }
        return 0;
    }
private:
    int sol2(int idx, int prev_idx, int n, vector<int>&nums,vector<vector<int>>&dp){
        if(idx == n) return 0;
        if(prev_idx != -1 && dp[idx][prev_idx] != -1) return dp[idx][prev_idx];
        
        int take = 0;
        if (prev_idx == -1 || nums[idx] > nums[prev_idx]){
            take = 1 + sol2(idx+1,idx,n,nums,dp);
        }
        int notTake = sol2(idx+1,prev_idx,n,nums,dp);
        
        if(prev_idx != -1) {
            dp[idx][prev_idx] = max(take, notTake);
        }
        return max(take, notTake);
    }
private:
    int sol3_binary_search( vector<int>&nums){
        int n = nums.size();
        vector<int>temp;
        temp.push_back(nums[0]);
        for(int i = 1 ; i < n ; i++){
            if (nums[i] > temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int idx = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[idx]= nums[i];
            }
        }
        return temp.size();
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // return sol1(0,-1,n,nums);
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return sol2(0,-1,n,nums,dp);
        return sol3_binary_search(nums);
    }
};
class sol2{
private:
    int getAns(int arr[], int n, int ind, int prev_index, vector<vector<int>>& dp) {
        // Base condition
        if (ind == n)
            return 0;
            
        if (dp[ind][prev_index + 1] != -1)
            return dp[ind][prev_index + 1];
        
        int notTake = 0 + getAns(arr, n, ind + 1, prev_index, dp);
        
        int take = 0;
        
        if (prev_index == -1 || arr[ind] > arr[prev_index]) {
            take = 1 + getAns(arr, n, ind + 1, ind, dp);
        }
        
        return dp[ind][prev_index + 1] = max(notTake, take);
    }
public:
    int longestIncreasingSubsequence(int arr[], int n) {
        // Create a 2D DP array initialized to -1
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        
        return getAns(arr, n, 0, -1, dp);
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>nums={10,9,2,5,3,7,101,18};
    cout<<solution.lengthOfLIS(nums)<<endl;
    return 0;
}