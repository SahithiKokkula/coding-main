#include<bits/stdc++.h>
using namespace std;
class disjointSet{
    vector<int> rank,parent,size;
public:

//find ultimate parent 
//find union (rank \ size)
    disjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }
    }

    int findUParent(int node){
        if (node == parent[node]){
            return node;
            return parent[node] = findUParent(parent[node]);
        }
    }

    void unionByRank(int u,int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }

    void unionBySize(int u,int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
class Solution{
public:
    void kruskals_algorithm(vector<vector<pair<int ,int>>>&adj,int V){
        vector<pair<int,pair<int,int>>>edges;
        vector<pair<int,int>>mst;
        for(int i = 0; i <V;i++){
            for(auto it:adj[i]){
                edges.push_back({it.second,{it.first,i}});
                //{wt,first node, second node};
            }
        }
        
        disjointSet ds(V);

        sort(edges.begin(),edges.end());
        int sum = 0; // weight
        for(auto it:edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if (ds.findUParent(u) != ds.findUParent(v)){
                sum+=wt;
                ds.unionBySize(u,v);
                mst.push_back({u,v});
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
    solution.kruskals_algorithm(adj,V); 
    return 0;
}