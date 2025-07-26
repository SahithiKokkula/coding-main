#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    bool check_palin(string s,int i ,int j ){
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
private:
    int sol1(int i, int j, string s,int n){
        if (j < i) return 0;
        int count = INT_MAX;
        for(int k = i + 1; k <= j; k++){
            count = min(count , 1 + (check_palin(s,i,k-1)?0:sol1(i,k-1,s,n)) + (check_palin(s,k,j)?0:sol1(k,j,s,n)));
        }
        return count;
    }
private:
    int sol2(int i, int j, string s,int n,vector<vector<int>>&dp){
        if (j <= i) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if (check_palin(s,i,j)) return 0;
        int count = INT_MAX;
        for(int k = i + 1; k <= j; k++){
            count = min(count , 1 + (check_palin(s,i,k-1)?0:sol2(i,k-1,s,n,dp)) + (check_palin(s,k,j)?0:sol2(k,j,s,n,dp)));
        }
        return dp[i][j] = count;
    }
private:
// front partitioning
int sol3(int i, int n, string &str) {
    // Base case: If we've reached the end of the string.
    if (i == n) return 0;

    int minCost = INT_MAX;
    // Consider all possible substrings starting from the current index.
    for (int j = i; j < n; j++) {
        if (check_palin(str,i, j)) {
            // If the substring is a palindrome, calculate the cost and minimize it.
            int cost = 1 + sol3(j + 1, n, str);
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}
private:
    int sol4(int i, int n, string &str, vector<int> &dp) {
    // Base case: If we've reached the end of the string.
    if (i == n) return 0;

    if (dp[i] != -1) return dp[i];
    int minCost = INT_MAX;
    // Consider all possible substrings starting from the current index.
    for (int j = i; j < n; j++) {
        if (check_palin(str,i, j)) {
            // If the substring is a palindrome, calculate the cost and minimize it.
            int cost = 1 + sol4(j + 1, n, str, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}
private:
    int sol5(int n, string str) {
        // Create a DP array to store the minimum number of partitions.
        vector<int> dp(n + 1, 0);
        dp[n] = 0; // Initialize the last element to 0.

        // Loop through the string in reverse order.
        for (int i = n - 1; i >= 0; i--) {
            int minCost = INT_MAX;
            // Consider all possible substrings starting from the current index.
            for (int j = i; j < n; j++) {
                if (check_palin(str,i, j)) {
                    // If the substring is a palindrome, calculate the cost and minimize it.
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }
        // Subtract 1 as it counts partitions, not cuts.
        return dp[0] - 1;
    }
public:
    int minCut(string s) {
        int n = s.size();
        // return sol1(0,n-1,s,n);
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return sol2(0,n-1,s,n,dp);
        return sol3(0,n,s) - 1;
        vector<int> dp2(n, -1);
        return sol4(0,n,s,dp2) - 1;
        return sol5(n, s);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s = "ab";
    cout<<solution.minCut(s);
    return 0;
}