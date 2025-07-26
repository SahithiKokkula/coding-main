#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int sol1(int i, int j, vector<int>& nums){
        if (i > j) return 0;

        int coins = 0;

        for(int k = i; k <= j; k++){
            coins = max(coins, nums[k] * nums[i - 1] * nums[j + 1] + sol1(i, k - 1, nums) + sol1(k + 1, j, nums));
        }

        return coins;
    }
private:
    int sol2(int i, int j, vector<int>& nums,vector<vector<int>>&dp){
        if (i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int coins = 0;

        for(int k = i; k <= j; k++){
            coins = max(coins, nums[k] * nums[i - 1] * nums[j + 1] + sol2(i, k - 1, nums,dp) + sol2(k + 1, j, nums,dp));
        }

        return dp[i][j] = coins;
    }
private:
    int sol3(int n, vector<int>& nums){
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));

        for(int i = n ; i >= 1 ; i--){
            for(int j = i ; j <= n ; j++){
                for(int k = i; k <= j; k++){
                    dp[i][j] = max(dp[i][j], nums[k] * nums[i - 1] * nums[j + 1] + dp[i][k-1] + dp[k+1][j]);
                }
            }
        }
        return dp[1][n];
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        arr.push_back(1);
        for (int x : nums) arr.push_back(x);
        arr.push_back(1);
        // return sol1(1, n, arr);

        // vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        // return sol2(1, n, arr,dp);

        return sol3(n,arr);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>nums = {3,1,5,8};
    cout<<solution.maxCoins(nums);
    return 0;
}