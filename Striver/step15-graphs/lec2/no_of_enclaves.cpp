#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i = 0 ; i < n ;i++){
            if (grid[i][0] == 1){
                q.push({i,0});
                vis[i][0] = 1;
            }
            if (grid[i][m-1] == 1){
                q.push({i,m-1});
                vis[i][m-1] = 1;
            }
        }
        for(int i = 0 ; i < m ;i++){
            if (grid[0][i] == 1){
                q.push({0,i});
                vis[0][i] = 1;
            }
            if (grid[n-1][i] == 1){
                q.push({n-1,i});
                vis[n-1][i] = 1;
            }
        }
        vector<pair<int,int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            auto node  = q.front();
            int i = node.first;
            int j = node.second;
            q.pop();
            for(int k = 0 ; k < 4 ; k++){
                int ni = i + dir[k].first;
                int nj = j +dir[k].second;
                if (ni >=0 && nj >= 0 && ni < n && nj < m && grid[i][j] == 1 && !vis[ni][nj]){
                    q.push({ni,nj});
                    vis[ni][nj] = 1;
                }
            }
        }
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ;j++){
                if(grid[i][j] == 1 && !vis[i][j]) cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<vector<int>>grid = {{0,0,0,1,1,1,0,1,0,0},{1,1,0,0,0,1,0,1,1,1},{0,0,0,1,1,1,0,1,0,0},{0,1,1,0,0,0,1,0,1,0},{0,1,1,1,1,1,0,0,1,0},{0,0,1,0,1,1,1,1,0,1},{0,1,1,0,0,0,1,1,1,1},{0,0,1,0,0,1,0,1,0,1},{1,0,1,0,1,1,0,0,0,0},{0,0,0,0,1,1,0,0,0,1}};
    cout<<solution.numEnclaves(grid);
    return 0;
}