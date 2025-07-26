#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int sol1(int i, int j, vector<int>cuts){
        if (i > j) return 0;
        int cost = INT_MAX;
        for(int idx = i ; idx <= j;idx++ ){
            cost = min(cost, cuts[j+1] - cuts[i-1] + sol1(i,idx-1,cuts) + sol1(idx+1,j,cuts));
        }
        return cost;
    }
private:
    int sol2(int i, int j, vector<int>cuts,vector<vector<int>>&dp){
        if (i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int cost = INT_MAX;
        for(int idx = i ; idx <= j;idx++ ){
            cost = min(cost, cuts[j+1] - cuts[i-1] + sol2(i,idx-1,cuts,dp) + sol2(idx+1,j,cuts,dp));
        }
        return dp[i][j] = cost;
    }
private:
    int sol3(vector<int>cuts,int n,int c){
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));
        for(int i = c; i > 0;i--){
            for(int j = 1;j<=c;j++){
                if(i>j) continue;
                int cost = INT_MAX;
                for(int idx = i ; idx <= j;idx++ ){
                    cost = min(cost, cuts[j+1] - cuts[i-1] + dp[i][idx-1] + dp[idx+1][j]);
                }
                dp[i][j] = cost;
            }
        }
        return dp[1][c];
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int c = cuts.size();
        // return sol1(1,cuts.size()-2,cuts);
        // vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        // return sol2(1,cuts.size()-2,cuts,dp);
        return sol3(cuts,n,c-2);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>cuts = {1,3,4,5};
    int n = 7;
    cout<<solution.minCost(n,cuts);
    return 0;
}