#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int sol1(int i,int j,int k,string& s1, string& s2, string& s3,vector<vector<vector<int>>>&dp){
        if (s1[i] == '\0' || s2[j] == '\0' || s3[k] == '\0') return 0;
        if (dp[i][j][k] != -1) return dp[i][j][k];
        int maxi = 0;
        if(s1[i] == s2[j] && s2[j] == s3[k]) maxi = max(maxi, 1 + sol1(i+1,j+1,k+1,s1,s2,s3,dp));
        else{
            vector<vector<int>>combinations = {{1,0,0},{0,1,0},{0,0,1},{1,1,0},{1,0,1},{0,1,1}};
            for(auto it: combinations){
                maxi = max(maxi,sol1(i + it[0],j + it[1] , k +it[2],s1,s2,s3,dp));
            }
        }
        return dp[i][j][k] = maxi;
    }
private:
    int sol2(int i,int j,int k,string& s1, string& s2, string& s3,vector<vector<vector<int>>>&dp){
        if (i < 0 || j < 0 || k < 0) return 0;
        if (dp[i][j][k] != -1) return dp[i][j][k];
        int maxi = 0;
        if(s1[i] == s2[j] && s2[j] == s3[k]) maxi = max(maxi, 1 + sol2(i-1,j-1,k-1,s1,s2,s3,dp));
        else{
            vector<vector<int>>combinations = {{1,0,0},{0,1,0},{0,0,1}};
            for(auto it: combinations){
                maxi = max(maxi,sol2(i - it[0],j - it[1] , k - it[2],s1,s2,s3,dp));
            }
        }
        return dp[i][j][k] = maxi;
    }
private:
    int sol3(string& s1, string& s2, string& s3){
            int n1 = s1.size(),n2 = s2.size(),n3=s3.size();

            vector<vector<vector<int>>>dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,0)));
            for(int i = 1 ; i <= n1; i++){
                for(int j = 1 ; j <= n2 ; j++){
                    for(int k = 1 ; k <= n3 ; k++){
                        int maxi = 0;
                        if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) maxi = max(maxi, 1 + dp[i-1][j-1][k-1]);
                        else{
                            vector<vector<int>>combinations = {{1,0,0},{0,1,0},{0,0,1},{1,1,0},{1,0,1},{0,1,1}};
                            for(auto it: combinations){
                                maxi = max(maxi,dp[i - it[0]][j - it[1]][k - it[2]]);
                            }
                        }
                        dp[i][j][k] = maxi;
                    }
                }
            }

        return dp[n1][n2][n3];
    }
private:
    int sol4(string& s1, string& s2, string& s3){
            int n1 = s1.size(),n2 = s2.size(),n3=s3.size();

            vector<vector<vector<int>>>dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,0)));
            for(int i = 1 ; i <= n1; i++){
                for(int j = 1 ; j <= n2 ; j++){
                    for(int k = 1 ; k <= n3 ; k++){
                        int maxi = 0;
                        if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) maxi = max(maxi, 1 + dp[i-1][j-1][k-1]);
                        else maxi = max({maxi,dp[i - 1][j][k],dp[i][j-1][k],dp[i][j][k-1]});
                        dp[i][j][k] = maxi;
                    }
                }
            }

        return dp[n1][n2][n3];
    }
public:
    int lcsOf3(string& s1, string& s2, string& s3) {
        vector<vector<vector<int>>>dp(s1.size(),vector<vector<int>>(s2.size(),vector<int>(s3.size(),-1)));
        // return sol1(0,0,0,s1,s2,s3,dp);
        // int n1 = s1.size(),n2 = s2.size(),n3=s3.size();
        // return sol2(n1 - 1,n2 - 1,n3 - 1,s1,s2,s3,dp);
        // return sol3(s1,s2,s3);
        return sol4(s1,s2,s3);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s1 = "abcd1e2", s2 = "bc12ea", s3 = "bd1ea";
    cout<< solution.lcsOf3(s1,s2,s3);
    return 0;
}