#include<bits/stdc++.h>
using namespace std;
class Solution {
    private:
        int dijkstra(vector<vector<int>>&heights,pair<int,int>initial,pair<int,int>final,int rows,int cols){
            vector<vector<int>>efforts_grid(rows, vector<int>(cols,INT_MAX));
            priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq; // min heap
            efforts_grid[initial.first][initial.second] = 0;
            pq.push({0,{initial.first,initial.second}});
            vector<pair<int,int>>direction = {{-1,0},{1,0},{0,1},{0,-1}};
            while(!pq.empty()){
                auto topele = pq.top();
                pq.pop();
                int x = topele.second.first;
                int y = topele.second.second;
                int effort = topele.first;
                for(int i = 0 ; i < 4 ; i++){
                    int new_x = x + direction[i].first;
                    int new_y = y + direction[i].second;
                    if (new_x >= 0 && new_y >= 0 && new_x < rows && new_y < cols){
                        int new_effort = max(effort , abs(heights[new_x][new_y] - heights[x][y]));
                        if (new_effort < efforts_grid[new_x][new_y]){
                            efforts_grid[new_x][new_y] = new_effort;
                            pq.push({new_effort,{new_x,new_y}});
                        }
                    }
                }
            }
            return efforts_grid[final.first][final.second];
        }
    public:
        int minimumEffortPath(vector<vector<int>>& heights) {
            int rows = heights.size();
            int cols = heights[0].size();
            pair<int,int> initial = {0,0};
            pair<int,int> final = {rows-1,cols-1};
            return dijkstra(heights,initial,final,rows,cols);
        }
};
int main(){
    vector<vector<int>>heights = {{1,10,6,7,9,10,4,9}};
    Solution solution;
    int result = solution.minimumEffortPath(heights);
    cout<<result;
}