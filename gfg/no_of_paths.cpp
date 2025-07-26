#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int dfs(vector<vector<int>>adj_list,int src,int dest,vector<int>&dp){
        if (src == dest) return 1;
        if(dp[src] != -1) return dp[src];
        int cnt = 0;
        for(auto it :adj_list[src]){
            cnt += dfs(adj_list,it,dest,dp);
        }
        return dp[src] = cnt;
    }
public:
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // Code here
        vector<vector<int>>adj_list(V,vector<int>());
        for(auto it:edges){
            adj_list[it[0]].push_back(it[1]);
        }
        vector<int>dp(V,-1);
        int cnt = dfs(adj_list,src,dest,dp);
        return cnt;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<vector<int>>edges = {{0,1}, {1,2}, {1,3}, {2,3}};
    int src = 0, dest = 3, V =4;
    cout<<solution.countPaths(edges,V,src,dest);
    return 0;
}