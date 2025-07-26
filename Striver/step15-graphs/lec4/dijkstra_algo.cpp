#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
vector<int> dijkstra_pq(vector<vector<pair<int, int>>> &adj, int src) {
    int n = adj.size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(n,INT_MAX);
    dist[src] = 0;
    pq.push({0,src});
    while(!pq.empty()){
        int dis = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        for(auto it: adj[curr]){
            int edgeWt = it.second;
            int adjNode = it.first;
            if (dis + edgeWt < dist[adjNode]){
                dist[adjNode] = dis + edgeWt;
                pq.push({dis+edgeWt , adjNode});
            }
        }

    }
    return dist;
}

public:
vector<int> dijkstra_set(vector<vector<pair<int, int>>> &adj, int src) {
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
    return dist;
}
};
int main(){
    int src = 2;
    vector<vector<pair<int,int>>>adj = {{{1,1},{2,6}},{{2,3},{0,1}},{{1,3},{0,6}}};
    Solution solution;
    vector<int>result_pq = solution.dijkstra_pq(adj,src);
    vector<int>result_set = solution.dijkstra_set(adj,src);
    for(auto it: result_pq){
        cout<<it<<" ";
    }
    cout<<endl;
    for(auto it: result_set){
        cout<<it<<" ";
    }
    return 0;    
}