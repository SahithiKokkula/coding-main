#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    int sol1(int k,vector<int>arr,int i){
        if (k==0) return 1;
        if (i==0) return ((arr[0]==k)?1:0);
        int not_take = sol1(k,arr,i-1);
        int take = 0;
        if(arr[i] <= k){
            take = sol1(k-arr[i],arr,i-1);
        }
        return take + not_take;
    }
private:
    int sol2(int k,vector<int>arr,int i,vector<vector<int>>&dp){
        if (k==0) return 1;
        if (i==0) return ((arr[0]==k)?1:0);
        if(dp[i][k] != -1 ) return dp[i][k];
        int not_take = sol2(k,arr,i-1,dp);
        int take = 0;
        if(arr[i] <= k){
            take = sol2(k-arr[i],arr,i-1,dp);
        }
        return dp[i][k] = take + not_take;
    }
private:
    int sol3(int n,int k,vector<int>arr,int i){
        vector<vector<int>>dp(n,vector<int>(k+1,0));
        for(int i = 0 ; i < n ; i++){
            dp[i][0] = 1;
        }
        dp[0][arr[0]] = arr[0]<=k?1:0;
        for(int i = 1 ; i < n ;i++){
            for(int j = 1 ; j <= k ;j++){
                int not_take = dp[i-1][j];
                int take = 0;
                if(arr[i] <= j){
                    take = dp[i-1][j-arr[i]];
                }
                dp[i][j] = take + not_take;
            }
        }
        return dp[n-1][k];
    }
private:
    int sol4(int n,int k,vector<int>arr,int i){
        vector<int>prev(k+1,0);
        prev[0] = 1;
        prev[arr[0]] = arr[0]<=k?1:0;
        for(int i = 1 ; i < n ;i++){
            vector<int>temp(k+1,0);
            temp[0] = 1;
            for(int j = 1 ; j <= k ;j++){
                int not_take = prev[j];
                int take = 0;
                if(arr[i] <= j){
                    take = prev[j-arr[i]];
                }
                temp[j] = take + not_take;
            }
            prev = temp;
        }
        return prev[k];
    }
public:
    int subsetSumToK(int n, int k, vector<int> &arr) {
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        // return sol1(k,arr,n-1);
        // return sol2(k,arr,n-1,dp);
        // return sol3(n,k,arr,n-1);
        return sol4(n,k,arr,n-1);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int n = 4;
    int k = 2;
    vector<int>arr = {1,2,3,4};
    cout<<solution.subsetSumToK(n,k,arr)<<endl;
    return 0;
}