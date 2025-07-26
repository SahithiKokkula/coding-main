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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        disjointSet ds(n*m);
        vector<vector<int>>visited(n,vector<int>(m,0));
        int cnt = 0;
        vector<int>ans;
        for(auto it : operators){
            int row = it[0];
            int col = it[1];
            if (visited[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            visited[row][col] = 1;
            cnt++;
            vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
            for(int i = 0 ;i < 4 ;i++){
                int adjr = row+dir[i].first;
                int adjc = col +dir[i].second;
                if (adjr<n && adjc <m && adjr >-1 && adjc >-1 && visited[adjr][adjc] == 1){
                    int node = row*m+col;
                    int adjnode = adjr *m+adjc;
                    if(ds.findUParent(node) != ds.findUParent(adjnode)){
                        cnt--;
                        ds.unionBySize(node,adjnode);
                    }
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int n = 4;
    int m = 5;
    int k = 4;
    vector<vector<int>>operators = {{0,0},{1,1},{2,2},{3,3}};
    vector<int>result = solution.numOfIslands(n,m,operators);
    for(auto it :result){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}

