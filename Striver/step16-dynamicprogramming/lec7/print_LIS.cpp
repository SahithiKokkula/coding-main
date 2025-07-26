#include<bits/stdc++.h>
using namespace std;

class sol2{
private:
    int getAns(vector<int>&arr, int n, int ind, int prev_index, vector<vector<int>>& dp) {
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
    private:
        int getAns_tab(vector<int>&arr, int n) {
            vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

            for(int i = n-1 ; i >=0; i--){
                for(int prev_idx = i-1 ; prev_idx >=-1 ; prev_idx--){
                    int notTake = 0 + dp[i+1][prev_idx+1];
                    
                    int take = 0;
                    
                    if (prev_idx == -1 || arr[i] > arr[prev_idx]) {
                        take = 1 + dp[i+1][i+1];
                    }
                    dp[i][prev_idx + 1] = max(notTake, take);
                }
            }
            return dp[0][0];


        }
public:
    int longestIncreasingSubsequence(vector<int>&arr, int n) {
        // Create a 2D DP array initialized to -1
        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        
        // return getAns(arr, n, 0, -1, dp);
        // return getAns_tab(arr,n);

        vector<int>dp(n,1) , hash(n);
        for (int i = 0; i < n; i++) {
            hash[i] = i; // Initialize hash with current index
        }
        int lastidx = 0;
        int maxi = 1;
        for(int i = 0 ; i < n ; i++){
            for(int prev = 0;prev<i;prev++){
                if (arr[prev] < arr[i] && dp[i] < dp[prev] + 1){
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }
            if (dp[i] > maxi){
                maxi = dp[i];
                lastidx = i;
            }
        }
        vector<int>ans;
        ans.push_back(arr[lastidx]);
        while(hash[lastidx] != lastidx){
            lastidx = hash[lastidx];
            ans.push_back(arr[lastidx]);
        }
        reverse(ans.begin(),ans.end());

        for(int i = 0 ; i < maxi;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

        return maxi;

    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sol2 solution;
    vector<int>nums={10,9,2,5,3,7,101,18};
    int n = nums.size();
    cout<<solution.longestIncreasingSubsequence(nums,n)<<endl;
    return 0;
}

