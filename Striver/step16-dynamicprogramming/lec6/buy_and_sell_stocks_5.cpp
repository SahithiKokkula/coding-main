#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int sol1(int i , int buy,vector<int>&prices,int n,vector<vector<int>>&dp,int fee){
        if (i == n) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy == 1){
            profit = max(-1*prices[i] + sol1(i+1,0,prices,n,dp,fee),sol1(i+1,1,prices,n,dp,fee));
        }
        else{
            profit = max(prices[i] + sol1(i+1,1,prices,n,dp,fee) - fee,sol1(i+1,0,prices,n,dp,fee));
        }
        return dp[i][buy] = profit;
    }
private:
    int sol3(vector<int>&prices,int n){
        vector<int>next(2,0);
        for(int i = n-1; i>=0;i--){
            vector<int>temp(2,0);
            for(int buy = 0 ; buy<=1;buy++){
                int profit = 0;

                if(buy == 1){
                    profit = max(-1*prices[i] + next[0] , next[1]);
                }
                else{
                    profit = max(prices[i] + next[1] , next[0]);
                }
                temp[buy] = profit;
            }
            next = temp;
        }
        return next[1] ;
    }
private:
    int sol2(vector<int>&prices,int n){
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][1] = dp[n][0] = 0;
        for(int i = n-1; i>=0;i--){
            for(int buy = 0 ; buy<=1;buy++){
                int profit = 0;
                if(buy == 1){
                    profit = max(-1*prices[i] + dp[i+1][0] , dp[i+1][1]);
                }
                else{
                    profit = max(prices[i] + dp[i+1][1] , dp[i+1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1] ;
    }
public:
    int maxProfit(vector<int>& prices,int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return sol1(0,1,prices,n,dp,fee);
        // return sol2(prices,n);
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>prices= {7,1,5,3,6,4};
    int fee = 2;
    cout<<solution.maxProfit(prices,fee)<<endl;
    return 0;
}