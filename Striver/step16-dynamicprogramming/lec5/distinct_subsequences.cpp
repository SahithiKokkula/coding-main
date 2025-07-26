#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int sol1(int i, int j,string s,string t,vector<vector<int>>&dp){
        if (j == 0) return 1;
        if (i == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int number = 0;
        if(s[i-1]==t[j-1]){
            number += sol1(i-1,j-1,s,t,dp);
        }
        number += sol1(i-1,j,s,t,dp);

        return dp[i][j] = number;
    }
    int sol2(int n,int m,string s,string t){
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = 0 ; i <= n ; i++){
            dp[i][0] = 1;
        }
        for(int i = 1 ; i <= n;i++){
            for(int j = 1 ; j <=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] += dp[i-1][j-1];
                }
                dp[i][j] += dp[i-1][j];
            }
        }
        return dp[n][m];
    }
    int sol3(int n,int m,string s,string t){
        vector<long long>prev(m+1,0);
        prev[0] = 1;
        for(int i = 1 ; i <= n;i++){
            vector<long long>temp(m+1,0);
            temp[0] = 1;
            for(int j = 1 ; j <=m;j++){
                if(s[i-1]==t[j-1]){
                    temp[j] += prev[j-1];
                }
                temp[j] += prev[j];
                if(temp[j] > INT_MAX) {
                    temp[j] = 0;  
                }
            }
            prev = temp;
        }
        return prev[m];
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return sol1(n,m,s,t,dp);
        // return sol2(n,m,s,t);
        return sol3(n,m,s,t);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s = "rabbbit", t = "rabbit";
    cout<<solution.numDistinct(s,t)<<endl;
    return 0;
}