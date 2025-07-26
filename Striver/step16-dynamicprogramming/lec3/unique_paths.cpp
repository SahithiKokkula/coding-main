#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    int sol1(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid){
        if (i>=0 && j>=0 && obstacleGrid[i][j] == 1) return 0;
        if (i == 0 && j == 0 ) return 1;
        if (i<0 || j<0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        dp[i][j] = sol1(i-1,j,dp,obstacleGrid) + sol1(i,j-1,dp,obstacleGrid);
        return dp[i][j];
    }
public:
    int uniquePaths(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return sol1(m-1,n-1,dp,obstacleGrid);
        
        vector<int>prevrow(n,0);
        for(int i = 0 ; i < m ; i++){
            vector<int>tmprow(n,0);
            for(int j = 0 ; j < n ;j++){
                if (i>=0 && j>=0 && obstacleGrid[i][j] == 1) tmprow[j] = 0;
                else if (i==0 && j==0) tmprow[j] = 1;
                else tmprow[j] = ((i>0)?prevrow[j]:0)+((j>0)?tmprow[j-1]:0);
            }
            prevrow = tmprow;
        }
        return prevrow[n-1];
    }
    
    int uniquePaths_tabu(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,1));
        // return sol1(m-1,n-1,dp);
        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ;j++){
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<vector<int>>obstacle_grid = {{0,0,0},{0,1,0},{0,0,0}};
    cout<<solution.uniquePaths(obstacle_grid);
    return 0;
}