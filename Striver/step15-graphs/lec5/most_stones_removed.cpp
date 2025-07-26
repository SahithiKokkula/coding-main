#include<bits/stdc++.h>
using namespace std;
class disjointSet{
public:
    vector<int> rank,parent,size;

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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        for(auto it : stones){
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        disjointSet ds(maxRow + maxCol +1);
        unordered_map<int,int>stonenodes;
        for(auto it :stones){
            int rownode = it[0];
            int colnode = it[1] + maxRow + 1;
            ds.unionBySize(rownode,colnode);
            stonenodes[rownode] = 1;
            stonenodes[colnode] = 1;
        }
        int count = 0;
        for(auto it:stonenodes){
            if (ds.findUParent(it.first) == it.first){
                count++;
            }
        }
        return n-count;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<vector<int>>stones = {{0,0},{0,2},{1,1},{2,0},{2,2}};
    cout<<solution.removeStones(stones);
    return 0;
}