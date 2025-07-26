#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();
        vector<bool>visited(n,0);
        vector<int>result(n,INT_MAX);
        queue<pair<int,int>>q;
        q.push({src,0});
        while (!q.empty()){
            int curr = q.front().first;
            int dist = q.front().second;
            result[curr] = min(result[curr],dist);
            visited[curr] = 1;
            q.pop();
            for(auto it : adj[curr]){
                if(!visited[it]){
                    q.push({it,dist+1});
                }
                result[it] = min(result[it],dist+1);
            }
        }
        for(int i = 0 ; i < n ; i ++){
            if(visited[i] == 0) result[i] = -1;
        }
        return result;
    }
};
int main(){
    int src = 0;
    vector<vector<int>>adj = {{1,3},{0,2},{1,6},{0,4},{3,5},{4,6},{2,5,7,8},{6,8},{7,6}};
    Solution solution;
    vector<int>result = solution.shortestPath(adj,src);
    for(auto it: result){
        cout<<it<<" ";
    }
    return 0;    
}