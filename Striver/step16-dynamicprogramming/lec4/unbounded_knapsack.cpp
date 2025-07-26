#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    int sol1(int i , int w, vector<int> &profit, vector<int> &weight){
        if(i == 0) {
            if (w==0) return 0;
            else if (w%weight[0] == 0) return profit[0]*(w/weight[0]);
            else return INT_MIN;
        }

        int not_take = sol1(i-1,w,profit,weight);
        int take = INT_MIN;
        if(w >= weight[i]) take = profit[i] + sol1(i,w-weight[i],profit,weight);

        return max(take,not_take);

    }
private:
    int sol2(int i , int w, vector<int> &profit, vector<int> &weight,vector<vector<int>>dp){
        if(i == 0) {
            if (w==0) return 0;
            if (weight[0] <= w && w%weight[0] == 0) return profit[0]*(w/weight[0]);
            else return -1e9;
        }
        if(dp[i][w] != -1) return dp[i][w];
        int not_take = sol2(i-1,w,profit,weight,dp);
        int take = -1e9;
        if(w >= weight[i]) take = profit[i] + sol2(i,w-weight[i],profit,weight,dp);

        return dp[i][w] = max(take,not_take);

    }
public:
    int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
        // Write Your Code Here.
        // int res = sol1(n-1,w,profit,weight);
        // return res!=INT_MIN?res:0;
        vector<vector<int>>dp(n,vector<int>(w+1,-1));
        int res = sol2(n-1,w,profit,weight,dp);
        return res!=-1e9?res:0;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int n = 2, w = 3;
    vector<int>profit = {6,12};
    vector<int>weight = {4,17};
    cout<<solution.unboundedKnapsack(n,w,profit,weight)<<endl;
    return 0;
}