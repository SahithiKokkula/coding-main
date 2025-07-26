#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int sol1(vector<vector<int>>&coins , int k,int i ,int j,vector<vector<vector<int>>>&dp){
        if (i < 0 || j < 0) return -1e9;
        if(dp[i][j][k] != -1)return dp[i][j][k];
        if(i == 0 && j == 0) {
            if (k>0 && coins[i][j] < 0) return 0;
            return coins[0][0];
        }
        
        int coin = -1e9;
        if (coins[i][j] < 0){
            if (k > 0){
                coin = max(coin, sol1(coins,k-1,i-1,j,dp));
                coin = max(coin, sol1(coins,k-1,i,j-1,dp));
            }
        }
        coin = max(coin, coins[i][j] + sol1(coins,k,i-1,j,dp));
        coin = max(coin, coins[i][j] + sol1(coins,k,i,j-1,dp));
        return dp[i][j][k] = coin;
    }
private:
    int sol2(vector<vector<int>>&coins){
        int m = coins.size();
        int n = coins[0].size();
        vector<vector<vector<int>>>dp(m + 1,vector<vector<int>>(n + 1,vector<int>(3,0)));

         for (int i = 1; i < m; i++) {
        for (int k = 0; k < 3; k++) {
            if (coins[i][0] < 0) {
                // Option 1: Skip this negative (if we have skips left)
                if (k > 0) {
                    dp[i][0][k] = max(dp[i][0][k], dp[i-1][0][k-1]);
                }
                // Option 2: Take this negative
                dp[i][0][k] = max(dp[i][0][k], coins[i][0] + dp[i-1][0][k]);
            } else {
                // Must take positive coins
                dp[i][0][k] = coins[i][0] + dp[i-1][0][k];
            }
        }
    }
    
    // Initialize first row (0,j)
    for (int j = 1; j < n; j++) {
        for (int k = 0; k < 3; k++) {
            if (coins[0][j] < 0) {
                if (k > 0) {
                    dp[0][j][k] = max(dp[0][j][k], dp[0][j-1][k-1]);
                }
                dp[0][j][k] = max(dp[0][j][k], coins[0][j] + dp[0][j-1][k]);
            } else {
                dp[0][j][k] = coins[0][j] + dp[0][j-1][k];
            }
        }
    }
        

        for(int i = 1 ; i < m ; i++ ){
            for(int j = 1 ; j < n ; j++){
                for(int k = 1 ; k < 3 ; k++){
                    int coin = -1e9;
                    if (coins[i][j] < 0){
                        if (k > 0){
                            coin = max(coin,dp[i - 1][j][k - 1]);
                            coin = max(coin, dp[i][j - 1][k - 1]);
                        }
                    }
                    coin = max(coin, coins[i][j] + dp[i - 1][j][k]);
                    coin = max(coin, coins[i][j] + dp[i][j - 1][k]);
                    dp[i][j][k] = coin;
                }
            }
        }
        return dp[m-1][n-1][2];
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        // int m = coins.size();
        // int n = coins[0].size();
        // vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(3,-1)));
        // return sol1(coins,2,m-1,n-1,dp);
        return sol2(coins);

    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<vector<int>>coins = {{0,1,-1},{1,-2,3},{2,-3,4}};
    cout<<solution.maximumAmount(coins);
    return 0;
}