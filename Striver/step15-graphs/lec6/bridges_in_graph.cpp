// Tarjan's Algorithm of time in and low time
#include<bits/stdc++.h>
using namespace std;

class Solution{
private:
    int timer = 1;
    void dfs(vector<vector<int>>&adj_list,int node , int parent, vector<int>&visited,vector<int>&time,vector<int>&min_time,vector<vector<int>>&result){
        visited[node] = 1;
        time[node] = min_time[node] = timer;
        timer++;
        for(auto it : adj_list[node]){
            if(it == parent) continue;
            if(visited[it] == 1) {
                min_time[node] = min(min_time[it],min_time[node]); 
            }
            else{
                dfs(adj_list,it,node,visited,time,min_time,result);
                min_time[node] = min(min_time[node] , min_time[it]);
                if (min_time[it] > time[node]){
                    result.push_back({node,it});
                }
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj_list(n,vector<int>());
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            adj_list[u].emplace_back(v);
            adj_list[v].emplace_back(u);
        }
        int timer = 1;
        vector<int>time(n);
        vector<int>min_time(n);
        vector<int>visited(n,0);
        vector<vector<int>>result;
        dfs(adj_list,0,-1,visited,time,min_time,result);
        return result;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int n = 4;
    vector<vector<int>>connections = {{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>>result = solution.criticalConnections(n,connections);
    for(auto it:result){
        cout<<it[0]<<" "<<it[1]<<endl;
    }
    return 0;
}