#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
//find minimum spanning tree (mst)
    void prims_algo(int V, vector<vector<pair<int,int>>>adj){
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<int>visited(V,0);
        vector<pair<int,int>>mst;
        pq.push({0,0,-1});
        int sum = 0;

        while(!pq.empty()){
            auto it = pq.top();
            int parent = it[2];
            int node = it[1];
            int wt = it[0];
            pq.pop();
            if (visited[node] == 1) continue;
            
            sum+=wt;
            visited[node] = 1;
            if (parent != -1){
                mst.push_back({parent,node});
            }
            for(auto it : adj[node]){
                if(!visited[it.first]){
                    pq.push({it.second,it.first,node});
                }
            }

        }
        cout<<sum<<endl;
        for(auto it : mst){
            cout<<it.first<<" "<<it.second<<" \n";
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int V = 5;
    vector<vector<pair<int ,int>>>adj = {{{2,1},{1,2}},{{0,1},{2,1}},{{0,1},{1,1},{4,2},{3,2}},{{4,1},{2,2}},{{2,2},{3,1}}};
    solution.prims_algo(V,adj);
    return 0;
}