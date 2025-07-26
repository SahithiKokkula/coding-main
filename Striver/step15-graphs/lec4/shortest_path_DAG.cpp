#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
	void dfs(int node, vector<int>&visited, stack<int> &st,vector<vector<pair<int,int>>>& adj) {
		visited[node] = 1;
		for (auto it : adj[node]) {
			if (!visited[it.first]) dfs(it.first, visited, st, adj);
		}
		st.push(node);
	}
private:
	//Function to return list containing vertices in Topological order.
	stack<int> topoSort(int V, vector<vector<pair<int,int>>> &adj)
	{
		vector<int>visited(V,0);
		stack<int> st;
		for (int i = 0; i < V; i++) {
			if (!visited[i]) {
				dfs(i, visited, st, adj);
			}
		}
        return st;
	}
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(V,vector<pair<int,int>>());
        for(auto it:edges){
            adj[it[0]].emplace_back(it[1] , it[2]);
        }
        int starting_node = 0;
        vector<int>result(V,INT_MAX);
        stack<int>st = topoSort(V,adj);
        result[starting_node] = 0;
        while(!st.empty()){
            int curr = st.top();
            int dist = result[curr];
            st.pop();
            if (result[curr] != INT_MAX){
                for(auto it : adj[curr]){
                    result[it.first] = min(result[it.first],dist + it.second);
                }
            }
            
        }
        for(int i = 0 ; i < V ; i++){
            if(result[i] == INT_MAX) result[i] = -1;
        }
        return result;
    }
};
int main(){
    int src = 0;
    vector<vector<int>>edges = {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};
    int V = 6;
    int E = 7;
    Solution solution;
    vector<int>result = solution.shortestPath(V,E,edges);
    for(auto it: result){
        cout<<it<<" ";
    }
    return 0;    
}