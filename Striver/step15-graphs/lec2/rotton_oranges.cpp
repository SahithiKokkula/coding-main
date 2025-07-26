#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int min_time_needed = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited = grid;
        queue<pair<pair<int,int>,int>>q ;
        for(int i = 0 ;i < m;i++){
            for(int j = 0; j < n ; j++){
                if(grid[i][j] == 2 ) q.push({{i,j},0});
            }
        }
        while(!q.empty()){
            int a = q.front().first.first;
            int b = q.front().first.second;
            int t = q.front().second;
            visited[a][b] = 2;
            q.pop();
            if (b+1 < n && grid[a][b+1] == 1){
                q.push({{a,b+1},t+1});
                min_time_needed = max(min_time_needed, t+1);
            }
            if (a+1 < m && grid[a+1][b] == 1){
                q.push({{a+1,b},t+1});
                min_time_needed = max(min_time_needed, t+1);
            }
            if (b-1 > -1 && grid[a][b-1] == 1){
                q.push({{a,b-1},t+1});
                min_time_needed = max(min_time_needed, t+1);
            }
            if (a-1 > -1 && grid[a-1][b] == 1){
                q.push({{a-1,b},t+1});
                min_time_needed = max(min_time_needed, t+1);
            }
        }
        bool check = 1;
        for(int i = 0 ;i < m;i++){
            for(int j = 0; j < n ; j++){
                if(visited[i][j] == 1 ) check = false;
            }
        }
        return (check)?min_time_needed:-1;
    }
};
int main(){
    int m, n;
    cin>>m>>n;

    vector<vector<int>>grid(m,vector<int>(n));
    for(int i = 0 ;i < m; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>grid[i][j];
        }
    }

    Solution solution;

    int result = solution.orangesRotting(grid);
    cout<<result<<endl;

    return 0;
}