#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int sol1(vector<vector<int>>&matrix,int n, int m){
        vector<vector<int>>dp(n,vector<int>(m,0));
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            dp[i][0] = matrix[i][0];    
            cnt += dp[i][0]; 
        }
        for(int i = 0 ; i < m ; i++){
            dp[0][i] = matrix[0][i];  
            cnt += dp[0][i];          
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 1) {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
                    cnt += dp[i][j];
                }
            }
        }
        return cnt;
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        return sol1(matrix , n, m);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<vector<int>>matrix = {{0,1,1,1},{1,1,1,1},{0,1,1,1}};
    cout<<solution.countSquares(matrix)<<endl;
    return 0;
}