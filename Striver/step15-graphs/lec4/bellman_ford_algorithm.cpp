#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int>distance(V,1e8);
        distance[src] = 0;
        // RELAXATION 

        for(int i = 0 ; i < V-1 ;i++){
            for(auto it : edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (distance[u] != 1e8 && distance[u] + wt < distance[v]){
                    distance[v] = distance[u] + wt;
                } 
            }
        }
        
        //check for negativecycle if nth iteration updates the distance array it have negative cycle
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (distance[u] != 1e8 && distance[u] + wt < distance[v]){
                return {-1};
            } 
        }
        
        return distance;
    }
};

int main(){
    vector<vector<int>> edges = {{3,2,6},{5,3,1},{0,1,5},{1,5,-3},{1,2,-2},{3,4,-2},{2,4,3}};
    int V = 6;
    int src = 0;
    Solution solution;
    vector<int>result = solution.bellmanFord(V,edges,src);
    for(auto it : result){
        cout<<((it == 1e8)?-1:it)<<" ";
    }
    cout<<endl;
    return 0;
}