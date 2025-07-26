#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int largestDivisibleSubset(vector<int>&arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<int>dp(n,1) , hash(n);
        for (int i = 0; i < n; i++) {
            hash[i] = i; 
        }
        int lastidx = 0;
        int maxi = 1;
        for(int i = 0 ; i < n ; i++){
            for(int prev = 0;prev<i;prev++){
                if ( arr[i]%arr[prev] == 0 && dp[i] < dp[prev] + 1){
                    dp[i] = dp[prev] + 1;
                    hash[i] = prev;
                }
            }
            if (dp[i] > maxi){
                maxi = dp[i];
                lastidx = i;
            }
        }
        vector<int>ans;
        ans.push_back(arr[lastidx]);
        while(hash[lastidx] != lastidx){
            lastidx = hash[lastidx];
            ans.push_back(arr[lastidx]);
        }
        reverse(ans.begin(),ans.end());

        for(int i = 0 ; i < maxi;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

        return maxi;

    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>nums = {1,4,8,12,9,3,18};
    cout<<solution.largestDivisibleSubset(nums);
    return 0;
}