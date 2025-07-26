#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    int sol(int i,int j1 ,int j2 ,vector<vector<int>>&grid ,int r, int c,vector<vector<vector<int>>>&dp){
        if(j1< 0 || j1 >= c || j2 <0 || j2 >= c) return INT_MIN;
        if (i == r-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }
        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        vector<int>dir = {1,0,-1};
        int maxi = -1;
        for(int p = 0 ; p <3 ;p++){
            for(int q = 0 ; q<3;q++){
                int newj1 = j1 + dir[p];
                int newj2 = j2 + dir[q];
                if (newj1 == newj2) maxi = max(maxi,grid[i][j1] + sol(i+1 , newj1,newj2,grid,r,c,dp));
                else maxi = max(maxi,grid[i][j1] + grid[i][j2] + sol(i+1 , newj1,newj2,grid,r,c,dp));
            }
        }
        dp[i][j1][j2] = maxi;
        return dp[i][j1][j2];
    }
private:
    int sol1(vector<vector<int>>&grid ,int r, int c){
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        
        for(int j1 = 0 ; j1 <c ;j1++){
            for(int j2 = 0 ; j2<c;j2++ ){
                if (j1 == j2 ) dp[r-1][j1][j2] = grid[r-1][j1];
                else dp[r-1][j1][j2] = grid[r-1][j1]+ grid[r-1][j2];
            }
        }
        for(int i = r-2 ; i >=0; i--){
            for(int j1 = 0 ; j1 < c;j1++){
                for(int j2 = 0 ;j2 <c;j2++){
                    vector<int>dir = {1,0,-1};
                    int maxi = INT_MIN;
                    for(int p = 0 ; p <3 ;p++){
                        for(int q = 0 ; q<3;q++){
                            int newj1 = j1 + dir[p];
                            int newj2 = j2 + dir[q];
                            if (newj1 >=0 && newj2 >= 0 && newj1 < c && newj2 < c){
                                if (newj1 == newj2) maxi = max(maxi,grid[i][j1] + dp[i+1][newj1][newj2]);
                                else maxi = max(maxi,grid[i][j1] + grid[i][j2] + dp[i+1][newj1][newj2]);
                            }
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][c-1];
    }
public:
    int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
        vector<vector<vector<int>>>dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return sol(0,0,c-1,grid,r,c,dp);
    }
    int maximumChocolates_tabu(int r, int c, vector<vector<int>> &grid) {
        return sol1(grid,r,c);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int r = 3;
    int c = 4;
    vector<vector<int>>grid = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    cout<<solution.maximumChocolates_tabu(r,c,grid);
    return 0;
}