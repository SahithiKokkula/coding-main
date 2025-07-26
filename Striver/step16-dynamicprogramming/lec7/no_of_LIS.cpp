#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int findNumberOfLIS(vector<int>&arr){
        int n = arr.size();
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
        
        int maxi = 1;
        for(int i = 0 ; i < n ; i++){
            for(int prev = 0;prev<i;prev++){
                if (arr[prev] < arr[i] && dp[i] < dp[prev] + 1){
                    dp[i] = dp[prev] + 1;
                    cnt[i] = cnt[prev];
                }
                else if (arr[prev] < arr[i] && dp[i] == dp[prev] + 1){
                    cnt[i]+=cnt[prev];
                }
            }
        }
        int c = 0;
        for(int i = 0 ; i < n ; i++){
            if (dp[i] > maxi){
                c = cnt[i];
                maxi = dp[i];
            }
            else if(dp[i] == maxi){
                c+=cnt[i];
            }
        }
        return c;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>arr = {10, 22, 9, 33, 21, 50, 41, 60, 80, 3};
    cout<<solution.findNumberOfLIS(arr);
    return 0;
}