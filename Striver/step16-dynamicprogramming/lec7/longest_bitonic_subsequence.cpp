#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int longest_bitonic(vector<int>&arr){
        int n = arr.size();
        vector<int>dp1(n,1);
        vector<int>dp2(n,1);

        int maxi = 1;
        for(int i = 0 ; i < n ; i++){
            for(int prev = 0;prev<i;prev++){
                if (arr[prev] < arr[i] && dp1[i] < dp1[prev] + 1){
                    dp1[i] = dp1[prev] + 1;
                }
            }
        }
        
        for(int i = n-1 ; i > -1 ; i--){
            for(int prev = n-1; prev > i; prev--){
                if (arr[prev] < arr[i] && dp2[i] < dp2[prev] + 1){
                    dp2[i] = dp2[prev] + 1;
                }
            }
        }
        for(int i = 0 ; i < n ;i++){
            maxi = max(maxi,dp1[i] + dp2[i] - 1);
        }
        return maxi;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>arr = {10, 22, 9, 33, 21, 50, 41, 60, 80, 3};
    cout<<solution.longest_bitonic(arr);
    return 0;
}