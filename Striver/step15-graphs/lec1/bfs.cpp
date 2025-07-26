#include<bits/stdc++.h>
using namespace std;
vector<int>bfs_graph(vector<vector<int>>adjacency_list){
    int node = 0; 
    vector<int>result;
    vector<int>visited(adjacency_list.size(),0);
    queue<int>q;
    visited[node] = 1;
    q.push(node);
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        result.push_back(curr);
        for(auto it : adjacency_list[curr]){
            if(visited[it] == 0){
                q.push(it);
                visited[it] = 1;
            }
        }
    }
    return result;
}

int main(){
    int n ,m;
    cin>>n>>m;
    int v ,u;
    vector<vector<int>>adjacency_list(n,vector<int>());
    for (int i = 0;i<m;i++){
        cin>>v>>u;
        adjacency_list[v].emplace_back(u);
        adjacency_list[u].emplace_back(v);
    }
    vector<int>result = bfs_graph(adjacency_list);
    for(auto it: result){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}