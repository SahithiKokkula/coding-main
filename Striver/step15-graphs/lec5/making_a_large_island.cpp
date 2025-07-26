#include<bits/stdc++.h>
using namespace std;
class disjointSet {
public:
    vector<int> rank, parent, size;
    disjointSet(int n) {
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findUParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution{
public:
    vector<vector<int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjointSet d(n*n);
        for (int i = 0 ; i< n ;i++){
            for (int j = 0 ; j < n ; j++){
                if(grid[i][j] == 0 ) continue;
                int node_no = n * i + j;
                for (auto it : directions){
                    int newi = i + it[0];
                    int newj = j + it[1];
                    if (newi < n && newi > -1 && newj > -1 && newj < n && grid[newi][newj] == 1){
                        int new_node_no = n * newi + newj;
                        d.unionBySize(node_no,new_node_no);
                    }
                }
            }
        }
        int maxi = INT_MIN;
        bool haszero = 0;
        for (int i = 0 ; i< n ;i++){
            for (int j = 0 ; j < n ; j++){
                unordered_set<int>st;
                if(grid[i][j] == 0 ){
                    haszero = 1;
                    for (auto it : directions){
                        int newi = i + it[0];
                        int newj = j + it[1];
                        if (newi < n && newi > -1 && newj > -1 && newj < n && grid[newi][newj] == 1){
                            int new_node_no = n * newi + newj;
                            st.insert(d.findUParent(new_node_no));
                        }
                    }
                    int sum = 1;
                    for (auto it :st){
                        sum += d.size[it];
                    }
                    maxi = max(maxi , sum );
                }
            }
        }
        if(haszero) return maxi;
        return n*n;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<vector<int>>grid = {{0,1},{1,0}};
    cout<<solution.largestIsland(grid);
    return 0;
}


