#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int sol1(int i, int j, string &text1, string &text2,vector<vector<int>>&dp) {
        if (i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + sol1(i-1, j-1, text1, text2,dp);
        } else {
            return dp[i][j] = max(sol1(i-1, j, text1, text2,dp), sol1(i, j-1, text1, text2,dp));
        }
        return dp[i][j] = -1;
    }
    int sol2(int n1, int n2, string &text1, string &text2) {
        vector<vector<int>>dp(n1,vector<int>(n2,0));
        bool c = 0;
        for (int i = 0 ; i < n1 ;i++){
            if (text1[i] == text2[0]) c = 1;
            if (c = 1) dp[i][0] = 1;
        }
        c = 0;
        for (int i = 0 ; i < n2 ;i++){
            if (text1[0] == text2[i]) c = 1;
            if (c = 1) dp[0][i] = 1;
        }
        for(int i = 1 ; i < n1 ;i++){
            for(int j = 1 ; j < n2 ;j++){
                if(text1[i] == text2[j]) dp[i][j]++;
                if (text1[i] == text2[j]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }    
        return dp[n1-1][n2-1];
    }
    int sol4(int n1, int n2, string &text1, string &text2) {
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
        for(int i = 1 ; i <= n1 ;i++){
            for(int j = 1 ; j <= n2 ;j++){
                if (text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }    
        return dp[n1][n2];
    }
    int sol3(int n1, int n2, string &text1, string &text2) {
        vector<vector<int>>dp(n1,vector<int>(n2,0));
        vector<int>prev(n2,0);
        prev[0] = (text1[0] == text2[0]) ? 1 : 0;
        for (int j = 1; j < n2; j++) {
            prev[j] = (text1[0] == text2[j]) ? 1 : prev[j-1];
        }
        for(int i = 1 ; i < n1 ;i++){
            vector<int>temp(n2,0);
            temp[0] = (text1[i] == text2[0]) ? 1 : prev[0];
            for(int j = 1 ; j < n2 ;j++){
                if(text1[i] == text2[j]) temp[j]++;
                if (text1[i] == text2[j]) {
                    temp[j] = 1 + prev[j-1];
                } else {
                    temp[j] = max(prev[j],temp[j-1]);
                }
            }
            prev = temp;
        }    
        return prev[n2-1];
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        // vector<vector<int>>dp(n1,vector<int>(n2,-1));
        // return sol1(n1-1,n2-1,text1,text2,dp);
        // return sol2(n1,n2,text1,text2);
        // return sol3(n1,n2,text1,text2);
        return sol4(n1,n2,text1,text2);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string text1 = "psnw";
    string text2 = "vozsh";
    cout<<solution.longestCommonSubsequence(text1,text2)<<endl;
    return 0;
}