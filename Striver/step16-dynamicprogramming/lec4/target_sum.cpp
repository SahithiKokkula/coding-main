#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    int sol1(int i ,int target, vector<int>&arr){
        if (i==0) return (abs(target) == arr[0])?1:0;

        int add = sol1(i-1,target - arr[i] , arr);
        int subtract = sol1(i-1 , target + arr[i] , arr);

        return add + subtract;
    }
private:
    int sol2(int i ,int target, vector<int>&arr,vector<vector<int>>&dp){
        if (i==0) return (abs(target) == arr[0])?1:0;
        if(dp[i][target+1000] != -1) return dp[i][target+1000];
        int add = sol2(i-1,target - arr[i] , arr,dp);
        int subtract = sol2(i-1 , target + arr[i] , arr,dp);
        return dp[i][target+1000] = add + subtract;
    }
private:
    int sol3(int n ,int target, vector<int>&arr){
        vector<vector<int>>dp(n,vector<int>(2000+1,0));

        dp[0][1000 + arr[0]] = 1;
        dp[0][1000 - arr[0]] += 1;
        for(int i = 1 ; i < n ;i++){
            for(int k = -1000 ;k<1000+1 ;k++){
                if(k - arr[i] + 1000 >= 0 && k - arr[i] + 1000 <= 2000) {
                    dp[i][k + 1000] += dp[i-1][k - arr[i] + 1000];
                }
                if(k + arr[i] + 1000 >= 0 && k + arr[i] + 1000 <= 2000) {
                    dp[i][k + 1000] += dp[i-1][k + arr[i] + 1000];
                }
            }
        }
        return (target >= -1000 && target <= 1000) ? dp[n-1][target + 1000] : 0;
    }
    
public:
    int targetSum(int n, int target, vector<int>& arr) {
        // return sol1(n-1,target,arr);
        vector<vector<int>>dp(n,vector<int>(2000+1,-1));
        // return sol2(n-1,target,arr,dp);
        return sol3(n,target,arr);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int n = 25;
    int target = 28;
    vector<int>arr = {47, 90, 93, 89, 72, 12, 80, 36, 18, 4, 60, 60, 57, 69, 66, 34, 26, 80, 92, 63, 22, 43, 65, 23, 84};
    cout<<solution.targetSum(n,target,arr)<<endl;
    return 0;
}