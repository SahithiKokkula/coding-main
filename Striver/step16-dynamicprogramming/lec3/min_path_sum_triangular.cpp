#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    int sol1(vector<vector<int>>&tri , int row ,int ele){
        if (row == 0) return tri[0][0];
        int mini = INT_MAX;
        if (ele<tri[row-1].size()) mini = min(tri[row][ele] + sol1(tri,row-1,ele),mini);
        if (ele>0) mini = min(tri[row][ele] + sol1(tri,row-1,ele-1),mini);
        return mini;
    }
private:
    int sol2(vector<vector<int>>&tri , int row ,int ele,vector<vector<int>>&dp){
        if (row == 0) return tri[0][0];
        if (dp[row][ele] != -1) return dp[row][ele];
        int mini = INT_MAX;
        if (ele<tri[row-1].size()) mini = min(tri[row][ele] + sol2(tri,row-1,ele,dp),mini);
        if (ele>0) mini = min(tri[row][ele] + sol2(tri,row-1,ele-1,dp),mini);
        dp[row][ele] = mini;
        return dp[row][ele];
    }
private:
    int sol3(vector<vector<int>>&tri,int n){
        vector<vector<int>>dp(n,vector<int>(n,-1));
        dp[0][0] = tri[0][0];
        int mini = INT_MAX;
        for(int i = 1 ; i<n ;i++){
            for(int  j = 0 ; j < i+1 ;j++){
                mini = INT_MAX;
                if(j>0) mini = min(mini, tri[i][j] + dp[i-1][j-1]);
                if (j<i) mini = min(mini,tri[i][j] + dp[i-1][j]);
                dp[i][j] = mini;
            }
        }
        mini = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            mini = min(dp[n-1][i],mini);
        }
        return mini;
    }
private:
    int sol4(vector<vector<int>>&tri,int n){
        int mini = INT_MAX;
        vector<int>prev(n,tri[0][0]);
        for(int i = 1 ; i<n ;i++){
            vector<int>temp(n,-1);
            for(int  j = 0 ; j < i+1 ;j++){
                mini = INT_MAX;
                if(j>0) mini = min(mini, tri[i][j] + prev[j-1]);
                if (j<i) mini = min(mini,tri[i][j] + prev[j]);
                temp[j] = mini;
            }
            prev = temp;
        }
        mini = INT_MAX;
        for(auto it:prev){
            mini = min(it,mini);
        }
        return mini;
    }
public:
    int minimumTotal_rec(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int mini = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            mini = min(mini,sol1(triangle,n-1,i));
        }
        return mini;
    }
public:
    int minimumTotal_memo(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int mini = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            mini = min(mini,sol2(triangle,n-1,i,dp));
        }
        return mini;
    }
public:
    int minimumTotal_tabu(vector<vector<int>>& triangle) {
        int n = triangle.size();
        return sol3(triangle,n);
    }
public:
    int minimumTotal_tabu_spo(vector<vector<int>>& triangle) {
        int n = triangle.size();
        return sol4(triangle,n);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<vector<int>>triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout<<solution.minimumTotal_rec(triangle)<<endl;
    cout<<solution.minimumTotal_memo(triangle)<<endl;
    cout<<solution.minimumTotal_tabu(triangle)<<endl;
    cout<<solution.minimumTotal_tabu_spo(triangle)<<endl;
    return 0;
}