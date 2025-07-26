#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int sol1(int i, int j, vector<int>&arr){
        if (i == j ) return 0;
        int mini = 1e9;
        for(int k = i ; k < j; k++){
            mini = min(mini , arr[i-1] * arr[k] * arr[j] + sol1(i,k,arr) + sol1(k+1,j,arr));
        }
        return mini;
    }
private:
    int sol2(int i, int j, vector<int>&arr,vector<vector<int>>&dp){
        if (i == j ) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for(int k = i ; k < j; k++){
            mini = min(mini , arr[i-1] * arr[k] * arr[j] + sol2(i,k,arr,dp) + sol2(k+1,j,arr,dp));
        }
        return dp[i][j] = mini;
    }
private:
    int sol3(int n, vector<int>&arr){
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i = n-1 ; i > 0; i--){
            for(int j = i + 1 ; j < n ; j++){
                int mini = 1e9;
                for(int k = i ; k < j; k++){
                    mini = min(mini , arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j] );
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n-1];
    }
public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        // return sol1(1,n-1,arr);
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return sol2(1,n-1,arr,dp);
        return sol3(n,arr);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>arr = {1, 2, 3, 4, 3};
    cout<<solution.matrixMultiplication(arr);
    return 0;
}