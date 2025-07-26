#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
        int dijkstra(vector<vector<int>>&grid,pair<int,int>initial,pair<int,int>final,int n){
            vector<vector<int>>dist_grid(n, vector<int>(n,INT_MAX));
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
            dist_grid[initial.first][initial.second] = 0;
            pq.push({0,{initial.first,initial.second}});
            vector<pair<int,int>>direction = {{-1,-1},{-1,0},{-1,1},{1,1},{1,0},{1,-1},{0,1},{0,-1}};
            while(!pq.empty()){
                int dis = pq.top().first;
                int x = pq.top().second.first;
                int y = pq.top().second.second;
                pq.pop();
                for(int i = 0 ; i < 8 ; i++){
                    int new_x = x + direction[i].first;
                    int new_y = y + direction[i].second;
                    if (new_x >=0 && new_y>= 0 && new_x < n && new_y < n && grid[new_x][new_y] == 0){
                        if((dis + 1) < dist_grid[new_x][new_y]){
                            dist_grid[new_x][new_y] = dis + 1;
                            pq.push({dis+1,{new_x,new_y}});
                        }
                    }
                }

            }
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j <n ;j++){
                    if (dist_grid[i][j] == INT_MAX){
                        dist_grid[i][j] = -2;
                    }
                }
            }
            return dist_grid[final.first][final.second] + 1;
        }
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            int n = grid.size();
            pair<int,int> initial = {0,0};
            pair<int,int> final = {n-1,n-1};
            if (grid[initial.first][initial.second] == 1) return -1;
            return dijkstra(grid,initial,final,n);
        }
};
int main(){
    vector<vector<int>>grid = {{1,0 ,0},{1,1,0},{1,1,0}};
    Solution solution;
    int result = solution.shortestPathBinaryMatrix(grid);
    cout<<result;
}