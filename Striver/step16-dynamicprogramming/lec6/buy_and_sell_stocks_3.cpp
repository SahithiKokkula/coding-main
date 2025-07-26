#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int sol1(int i , int buy,int times,vector<int>&prices,int n,vector<vector<vector<int>>>&dp){
        if(times == 0) return 0;
        if (i == n) return 0;
        if (dp[i][buy][times] != -1) return dp[i][buy][times];
        int profit = 0;
        if(buy == 1){
            profit = max(-1*prices[i] + sol1(i+1,0,times,prices,n,dp),sol1(i+1,1,times,prices,n,dp));
        }
        else{
            profit = max(prices[i] + sol1(i+1,1,times-1,prices,n,dp),sol1(i+1,0,times,prices,n,dp));
        }
        return dp[i][buy][times] = profit;
    }
private:
    int sol2(vector<int>&prices,int n,int times){
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(times+1,0)));
        for(int i = n-1; i>=0;i--){
            for(int buy = 0 ; buy<=1;buy++){
                for(int k = 1 ; k <= times;k++){
                    int profit = 0;
                    if(buy == 1){
                        profit = max(-1*prices[i] + dp[i+1][0][k] ,dp[i+1][1][k]);
                    }
                    else{
                        profit = max(prices[i] + dp[i+1][1][k-1] , dp[i+1][0][k]);
                    }
                    dp[i][buy][k] = profit;
                }
            }
        }
        return dp[0][1][times];
    }

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int times = 2;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(times+1,-1)));
        // return sol1(0,1,times,prices,n,dp);
        return sol2(prices,n,times);
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>prices= {3,3,5,0,0,3,1,4};
    cout<<solution.maxProfit(prices)<<endl;
    return 0;
}