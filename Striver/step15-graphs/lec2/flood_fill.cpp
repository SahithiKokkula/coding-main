#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,0));
        queue<pair<pair<int,int>,int>>qu;
        qu.push({{sr,sc},image[sr][sc]});
        image[sr][sc] = color;
        vector<int>directx = {1,-1,0,0};
        vector<int>directy = {0,0,1,-1};
        while(!qu.empty()){
            int currx = qu.front().first.first;
            int curry = qu.front().first.second;
            int prev_color = qu.front().second;
            qu.pop();
            for(int i = 0 ; i < 4 ;i++){
                int x = directx[i] + currx;
                int y = directy[i] + curry;
                if (x > -1 && y > -1 && x < m && y < n && image[x][y] == prev_color && visited[x][y] == 0){
                    qu.push({{x,y},prev_color});
                    image[x][y] = color;
                    visited[x][y] = 1;
                }
            }
        }
        return image;
    }
};
int main(){
    int m, n, sr, sc, color;
    cin>>m>>n,sr,sc,color;

    vector<vector<int>>grid(m,vector<int>(n));
    for(int i = 0 ;i < m; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>grid[i][j];
        }
    }

    Solution solution;

    vector<vector<int>> result = solution.floodFill(grid,sr,sc,color);
    for(auto it: result){
        for(auto itr : it){
            cout<<itr<<endl;
        }
        cout<<endl;
    }

    return 0;
}