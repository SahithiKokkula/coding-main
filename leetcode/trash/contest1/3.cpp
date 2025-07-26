#include<bits/stdc++.h>
using namespace std;
class Solution{
public:

int dijkstra(vector<vector<pair<int, int>>> &adj, int src,int finalnode) {
    set<pair<int,int>>st;
    int n = adj.size();
    vector<int>dist(n,INT_MAX);
    dist[src] = 0;
    st.insert({0,src});
    while (!st.empty()){
        int curr = (*(st.begin())).second;
        int dis = (*(st.begin())).first;
        st.erase(st.begin());
        for(auto it : adj[curr]){
            int edgewt = it.second;
            int adjedge = it.first;
            if(dist[adjedge] > dis + edgewt){
                if (dist[adjedge] != INT_MAX){
                    st.erase({dist[adjedge],adjedge});
                }
                dist[adjedge] = dis + edgewt;
                st.insert({dis+edgewt, adjedge});
            }
        }
    }
    return dist[finalnode];
}
vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
    vector<vector<pair<int, int>>> adj(n);
    vector<int>result;
    for(auto it : edges){
        int u = it[0]-1;
        int v = it[1]-1;
        int wt = it[2] ;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    for(auto it:queries){
        if (it[0] == 2){
            result.push_back(dijkstra(adj,0,it[1]-1));
        }
        else{
            int u = it[1]-1;
            int v = it[2]-1;
            int wtn = it[3];
            for(auto &itt : adj[u]){
                if(itt.first == v){
                    itt.second = wtn;
                    break;
                }
            }
            for(auto &itt : adj[v]){
                if(itt.first == u){
                    itt.second = wtn;
                    break;
                }
            }
        }
    }
    return result;
}
};
int main(){
    int src = 2;
    vector<vector<int>>edges = {{1,2,2},{1,3,4}};
    vector<vector<int>>queries={{2,1},{2,3},{1,1,3,7},{2,2},{2,3}};int n = 3;
    Solution solution;
    vector<int>result = solution.treeQueries(n,edges,queries);
    for(auto it: result){
        cout<<it<<" ";
    }
    return 0;    
}



