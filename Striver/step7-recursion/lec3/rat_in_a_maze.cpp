#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    void sol1(vector<vector<int>>&arr,vector<string>&result,int i ,int j ,int n, string res,vector<vector<bool>>&vis){
        if (i == n-1 && j == n-1) {
            result.push_back(res);
            return;
        }

        vector<vector<int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};
        vector<string>di = {"R","L" ,"D","U"};
        for(int it = 0 ; it < 4 ;it++){
            int ni = i + dir[it][0];
            int nj = j + dir[it][1];
            if(ni >= 0 && ni < n && nj >=0 && nj<n && arr[ni][nj] == 1 && vis[ni][nj] == 0){
                vis[ni][nj] = 1;
                sol1(arr,result,ni,nj,n, res+di[it],vis);
                vis[ni][nj] = 0;
            }
        }
    }
public:
    vector < string > searchMaze(vector < vector < int >> & arr, int n) {
        vector<string>result;
        vector<vector<bool>>vis(n,vector<bool>(n,0));
        vis[0][0] = 1;
        sol1(arr,result,0,0,n,"",vis);
        sort(result.begin(),result.end());
        return result;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int n = 3;
    vector<vector<int>> arr = {{1,1,1 },{1,0,1},{1,1,1}};
    vector<string>result = solution.searchMaze(arr,n);
    for(auto it:result){
        cout<<it<<" ";
    }
    return 0;
}