#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int sol1(int i , int buy,int status ,vector<int>&prices,int n,vector<vector<vector<int>>>&dp,int cooldown){
        if (i == n) return 0;
        if (dp[i][buy][status] != -1) return dp[i][buy][status];
        int profit = 0;
        if (status>0){
            profit = sol1(i+1,buy,status -1,prices,n,dp,cooldown);
        }
        else if(buy == 1){
            profit = max(-1*prices[i] + sol1(i+1,0,status,prices,n,dp,cooldown),sol1(i+1,1,status,prices,n,dp,cooldown));
        }
        else{
            profit = max(prices[i] + sol1(i+1,1,cooldown,prices,n,dp,cooldown),sol1(i+1,0,status,prices,n,dp,cooldown));
        }
        return  dp[i][buy][status] = profit;
    }

private:
    int sol2(vector<int>&prices,int n,int cooldown){
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(cooldown+1,0)));
        for(int i = n-1; i>=0;i--){
            for(int buy = 0 ; buy<=1;buy++){
                for(int k = 0 ;k <= cooldown;k++){
                    int profit = 0;
                    if (k>0){
                        profit = dp[i+1][buy][k - 1] ;
                    }
                    else if(buy == 1){
                        profit = max(-1*prices[i] + dp[i+1][0][k] , dp[i+1][1][k]);
                    }
                    else{
                        profit = max(prices[i] + dp[i+1][1][cooldown] , dp[i+1][0][k]);
                    }
                    dp[i][buy][k] = profit;
                }
                
            }
        }
        return dp[0][1][0];
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cooldown = 1;
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(cooldown+1,-1)));
        // return sol1(0,1,0,prices,n,dp,cooldown);
        return sol2(prices,n,cooldown);
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>prices= {1,2,3,0,2};
    cout<<solution.maxProfit(prices)<<endl;
    return 0;
}