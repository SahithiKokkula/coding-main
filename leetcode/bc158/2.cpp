#include<bits/stdc++.h>
using namespace std;


//status :  0 -> doing nothing (buy/sell/pass)
//status :  1 -> buy (sell/pass)
//status :  2 -> sell (buy/pass)
class Solution {
private:
    long long sol1(int i , int status,int times,vector<int>&prices,int n,vector<vector<vector<long long>>>&dp){
        if(times == 0) return 0;
        if (i == n - 1) {
            if (status == 0) return 0;
            else if (status == 1) return prices[i];
            else return -1 * prices[i];
        }

        if(dp[i][status][times] != -1) return dp[i][status][times];

        long long profit = sol1(i+1,status,times,prices,n,dp);

        if(status == 0){
            profit = max(profit, (long long) -1 * prices[i] + sol1(i+1,1,times,prices,n,dp));
            profit = max(profit, (long long) prices[i] + sol1(i+1,2,times,prices,n,dp));
        }
        else if(status == 1){
            profit = max(profit, (long long) prices[i] + sol1(i+1,0,times - 1,prices,n,dp));
        }
        else{
            profit = max(profit, (long long) -1 * prices[i] + sol1(i+1,0,times - 1,prices,n,dp));
        }
        return dp[i][status][times] = profit;
    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        int times = k;
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(3,vector<long long>(times+1,-1)));
        return sol1(0,0,k,prices,n,dp);
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>prices= {1,7,9,8,2};
    cout<<solution.maximumProfit(prices, 2)<<endl;
    return 0;
}