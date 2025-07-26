#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(),coins.end());

        int n = coins.size();
        __int128 result = 0,currSum = 0;

        // for(int i = 0 , j = 0; i < n ;i++){
        //     while(j<n && coins[j][1] <= coins[i][0] + k - 1){
        //         currSum += (long long)(coins[j][1] - coins[j][0] + 1) * coins[j][2];
        //         j++;
        //     }
        //     if (j<n){
        //         __int128 partialsum = (long long) (max(0,coins[i][0] + k - coins[j][0] + 1) * coins[j][2]);
        //         result = max(result,currSum + partialsum);
        //     }
        //     currSum -= (long long) (coins[i][1] - coins[i][0] + 1) * coins[i][2]; 
        // }
        // currSum = 0;
        // for(int i = 0 , j = 0 ; i< n ; i++){
        //     currSum += (long long) (coins[i][1] - coins[i][0] + 1) * coins[i][2];

        //     while(coins[j][1] <= coins[i][1] - k + 1){
        //         currSum -= (long long) (coins[j][1] - coins[j][0] + 1) * coins[j][2];
        //         j++;
        //     }
        //     __int128 partial = (long long) max(0,coins[i][1] - k + 1 - coins[j][0]) * coins[j][2];
        //     result = max(result , currSum - partial);
        // }
        for(int i = 0 , j = 0; i < n ;i++){
            while(j<n && coins[j][1] <= coins[i][0] + k - 1){
                currSum += (long long)((coins[j][1] - coins[j][0] + 1) * coins[j][2]);
                j++;
            }
            if (j<n){
                __int128 partialsum = (long long) (max(0,coins[i][0] + k - coins[j][0]) * coins[j][2]);
                result = max(result,currSum + partialsum);
            } else {
                result = max(result, currSum);
            }
            currSum -= (long long) ((coins[i][1] - coins[i][0] + 1) * coins[i][2]); 
        }
        currSum = 0;
        for(int i = 0 , j = 0 ; i< n ; i++){
            currSum += (long long) (coins[i][1] - coins[i][0] + 1) * coins[i][2];

            while(j < n && coins[j][1] < coins[i][1] - k + 1){
                currSum -= (long long) (coins[j][1] - coins[j][0] + 1) * coins[j][2];
                j++;
            }
            if (j < n) {
                __int128 partial = (long long) (max(0, coins[i][1] - k + 1 - coins[j][0]) * coins[j][2]);
                result = max(result , currSum - partial);
            } else {
                result = max(result, currSum);
            }
        }
        return (long long) result;
    }
};

class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        int n = coins.size();
        if (n == 0) return 0;
        
        // Sort by start
        sort(coins.begin(), coins.end());
        long long result = 0;

        // First pass: align window start with coin starts
        long long currSum = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            long long start = coins[i][0];
            while (j < n && coins[j][1] <= start + k - 1) {
                currSum += static_cast<long long>(coins[j][1] - coins[j][0] + 1) * coins[j][2];
                j++;
            }
            if (j < n) {
                long long overlap = max(0LL, start + k - coins[j][0]);
                result = max(result, currSum + overlap * coins[j][2]);
            } else {
                result = max(result, currSum);
            }
            currSum -= static_cast<long long>(coins[i][1] - coins[i][0] + 1) * coins[i][2];
        }

        // Second pass: align window end with coin ends
        // Sort by end
        sort(coins.begin(), coins.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        currSum = 0;
        j = 0;
        for (int i = 0; i < n; i++) {
            long long end_val = coins[i][1];
            long long L = end_val - k + 1;
            currSum += static_cast<long long>(coins[i][1] - coins[i][0] + 1) * coins[i][2];
            
            // Remove coins that end < L (using sorted-by-end array)
            while (j < n && coins[j][1] < L) {
                currSum -= static_cast<long long>(coins[j][1] - coins[j][0] + 1) * coins[j][2];
                j++;
            }
            
            // Find the first coin in [j, i] that starts >= L
            int left = j;
            int right = i;
            int idx = i + 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (coins[mid][0] >= L) {
                    idx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            
            // Calculate the sum of v and a*v from j to idx-1
            long long sum_v = 0;
            long long sum_av = 0;
            for (int m = j; m < idx; m++) {
                sum_v += coins[m][2];
                sum_av += static_cast<long long>(coins[m][0]) * coins[m][2];
            }
            
            // The left part to subtract: L * sum_v - sum_av
            long long leftPart = L * sum_v - sum_av;
            result = max(result, currSum - leftPart);
        }
        
        return result;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}