#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    string sol4(int n1, int n2, string &text1, string &text2) {
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        
        for(int i = 1 ; i <= n1 ;i++){
            for(int j = 1 ; j <= n2 ;j++){
                if (text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }    
        
        int i = n1;
        int j = n2;
        string ans = "";
        while(i>0 && j>0){
            if(text1[i-1] == text2[j-1]){
                ans += text1[i-1];
                i--;
                j--;
            }
            else if (dp[i-1][j] > dp[i][j-1]){
                ans += text1[i-1];
                i--;
            }
            else{
                ans += text2[j-1];
                j--;
            }
        }
        while(i>0){
            ans += text1[--i];
        }
        while(j>0){
            ans += text2[--j];
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        return sol4(n1,n2,text1,text2);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string text1 = "brute";
    string text2 = "groot";
    cout<<solution.shortestCommonSupersequence(text1,text2)<<endl;
    return 0;
}