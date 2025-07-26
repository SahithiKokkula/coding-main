#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    void dfs(vector<vector<int>>&adj_list,vector<int>&vis,vector<pair<int,int>>&edges,pair<int,int>&data){
        
    }
public:
    void solve(){
        int n;
        cin>>n;
        vector<vector<int>>adj_list(n,vector<int>());
        int u,v;
        for(int i = 0 ; i < n -1 ; i ++){
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        vector<int>vis(n,0);
        vector<pair<int,int>>edges;
        pair<int,int>data = {0,n}; //nodes dn , rem edges

        dfs(adj_list,vis,edges,data); 
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int t;
    cin>>t;
    while(t--){
        solution.solve();
    }
    return 0;
}