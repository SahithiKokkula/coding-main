#include<bits/stdc++.h>
using namespace std;
class disjointSet {
    vector<int> rank, parent, size;
public:
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
    int do_works(int t , vector<vector<int>>&grid,int n){
        disjointSet d(n*n);
        vector<vector<int>>directions = {{1,0},{-1,0}, { 0,1},{0,-1}};
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n; j++){
                if ( grid[i][j]> t) continue;
                int node = i * n + j;
                for(auto it: directions){
                    int newi = i +it[0];
                    int newj = j + it[1];
                    int new_node = newi * n + newj;
                    if (newi > -1 && newj > -1 && newi <n && newj < n && grid[newi][newj] <= t){
                        d.unionByRank(node,new_node);
                    }
                }
            }
        }
        int last_node = n*n-1;
        if (d.findUParent(last_node) == d.findUParent(0)) return 1 ;
        return 0;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxi = INT_MIN;
        for(auto it : grid){
            for(auto itt: it){
                maxi = max(maxi,itt);
            }
        }

        // binary search
        int low  = grid[0][0];
        int high = n*n-1;
        int ans = maxi;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int chek = do_works(mid , grid,n);
            if (chek == 1){
                ans = mid;
                high = mid-1;
            }
            else if(chek == 0){
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<vector<int>>grid = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
    cout<<solution.swimInWater(grid);
    return 0;
}