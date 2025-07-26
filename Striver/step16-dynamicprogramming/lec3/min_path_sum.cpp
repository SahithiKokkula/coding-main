#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    int sol1(int i,int j,vector<vector<int>>&dp,vector<vector<int>> &grid){
        if (i == 0 && j == 0 ) return grid[i][j];
        if (i<0 || j<0) return 1e9;
        if (dp[i][j] != -1) return dp[i][j];
        dp[i][j] = min( sol1(i-1,j,dp,grid) + grid[i][j], sol1(i,j-1,dp,grid)+ grid[i][j]);
        return dp[i][j];
    }
public:
    int uniquePaths(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();

        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return sol1(n-1,m-1,dp,grid);

        // return uniquePaths_tabu(m,n,grid);
        
        vector<int>prevrow(m,0);
        for(int i = 0 ; i < n ; i++){
            vector<int>tmprow(m,0);
            for(int j = 0 ; j < m ;j++){
                if (i==0 && j== 0 ) tmprow[j] = grid[i][j];
                else{
                    int up = grid[i][j];
                    if(i>0) up+=prevrow[j];
                    else up += 1e9;
                    int left = grid[i][j];
                    if (j>0) left+= tmprow[j-1];
                    else left += 1e9;
                    tmprow[j] = min(left ,up);
                }
            }
            prevrow = tmprow;
        }
        return prevrow[m-1];
    }
    
    int uniquePaths_tabu(int m, int n,vector<vector<int>> &grid) {
        swap(m,n);
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ;j++){
                if (i==0 && j== 0 ) dp[i][j] = grid[i][j];
                else{
                    int up = grid[i][j];
                    if(i>0) up+=dp[i-1][j];
                    else up += 1e9;
                    int left = grid[i][j];
                    if (j>0) left+= dp[i][j-1];
                    else left += 1e9;
                    dp[i][j] = min(left ,up);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<vector<int>>obstacle_grid = {{5,9,6},{11,5,2}};
    cout<<solution.uniquePaths(obstacle_grid);
    return 0;
}