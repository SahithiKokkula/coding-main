#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    int sol1(int k,vector<int>arr,int i){
        if (i == 0){
            if (k%arr[0] == 0) return k/arr[0];
            else return INT_MAX;
        }

        int not_take = 0 + sol1(k,arr,i-1);
        int take = INT_MAX;
        if (k >= arr[i]){
            int res = sol1(k-arr[i],arr,i);
            if (res!=INT_MAX) take = 1 + res;
        }
        return min(take,not_take);
    }
private:
    int sol2(int k,vector<int>arr,int i,vector<vector<int>>&dp){
        if (i == 0){
            if (k%arr[0] == 0) return k/arr[0];
            else return INT_MAX;
        }
        if(dp[i][k] != -1) return dp[i][k];
        int not_take = 0 + sol1(k,arr,i-1);
        int take = INT_MAX;
        if (k >= arr[i]){
            int res = sol1(k-arr[i],arr,i);
            if (res!=INT_MAX) take = 1 + res;
        }
        return dp[i][k] = min(take,not_take);
    }
private:
    int sol3(int n,int k,vector<int>arr){

        vector<vector<int>>dp(n,vector<int>(k+1,0));
        for(int i = 0 ; i < n ; i++){
            dp[i][0] = 0;
        }
        for(int target = 1 ; target <= k ; target++){
            dp[0][target] = (target%arr[0] == 0)?target/arr[0]:INT_MAX;
        }

        for(int i = 1 ; i < n ;i++){
            for(int j = 1 ; j <= k ;j++){
                int not_take = dp[i-1][j];

                int take = INT_MAX;
                if (j >= arr[i]){
                    int res = dp[i][j-arr[i]];
                    if (res!=INT_MAX) take = 1 + res;
                }
                dp[i][j] = min(take , not_take);
            }
        }
        return (dp[n-1][k] == INT_MAX)?-1:dp[n-1][k];
    }
public:
    int subsetSumToK(int n, int k, vector<int> &arr) {
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        // return sol1(k,arr,n-1);
        // return sol2(k,arr,n-1,dp);
        return sol3(n,k,arr);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int n = 3;
    int k = 3;
    vector<int>arr = {1,2,3};
    cout<<solution.subsetSumToK(n,k,arr)<<endl;
    return 0;
}