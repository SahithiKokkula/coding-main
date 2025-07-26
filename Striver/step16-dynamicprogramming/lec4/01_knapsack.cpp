#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int sol1(int idx, int w, vector<int> &val, vector<int> &wt,vector<vector<int>>&dp){
        if (w <= 0) return 0;
        if(idx < 0) return 0;
        if(dp[idx][w] != -1) return dp[idx][w];
        int pic = 0, not_pic = 0;
        if(wt[idx] <= w){
            pic = val[idx] + sol1(idx-1,w-wt[idx],val,wt,dp);
        }
        not_pic = sol1(idx-1,w,val,wt,dp);
        return dp[idx][w] = max(pic,not_pic);
    }
private:
    int sol1(int idx, int w, vector<int> &val, vector<int> &wt,vector<vector<int>>&dp){
        if (w <= 0) return 0;
        if(idx < 0) return 0;
        if(dp[idx][w] != -1) return dp[idx][w];
        int pic = 0, not_pic = 0;
        if(wt[idx] <= w){
            pic = val[idx] + sol1(idx-1,w-wt[idx],val,wt,dp);
        }
        not_pic = sol1(idx-1,w,val,wt,dp);
        return dp[idx][w] = max(pic,not_pic);
    }
public:
    int knapsack(int w, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>>dp(n,vector<int>(w+1,-1));
        return sol1(n-1,w,val,wt,dp);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int> val ={10, 40, 30, 50}, wt = {5, 4, 2, 3};
    int W = 5;
    cout<<solution.knapsack(W,val,wt);
    return 0;
}