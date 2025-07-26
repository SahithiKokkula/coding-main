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
        if (node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    disjointSet ds(5);
    return 0;
}