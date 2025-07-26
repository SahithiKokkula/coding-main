#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>>pref_sum(m,vector<long long>(n,0));
        
        pref_sum[0][0] = grid[0][0];
        for(int i = 1 ; i < n ; i++){
            pref_sum[0][i] = pref_sum[0][i-1] + grid[0][i];
        }
        for(int i = 1 ; i < m ; i++){
            pref_sum[i][0] = pref_sum[i-1][0] + grid[i][0];
        }

        for(int i = 1; i < m; i ++){
            for(int j = 1 ; j < n ; j ++){
                pref_sum[i][j] = pref_sum[i-1][j] + pref_sum[i][j-1] - pref_sum[i-1][j-1] + grid[i][j];
            }
        }
        bool flag = false;
        if(!flag){
            for(int i = 0 ; i < n - 1; i ++){
                if(pref_sum[m-1][n-1] - pref_sum[m-1][i] == pref_sum[m-1][i]){
                    flag = true;
                    break;
                }
            }
        }
        if(!flag){
            for(int i = 0 ; i < m - 1; i ++){
                if(pref_sum[m-1][n-1] - pref_sum[i][n-1] == pref_sum[i][n-1]){
                    flag = true;
                    break;
                }
            }
        }
        return flag;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<vector<int>>grid = {{1,4},{2,3}};
    cout<<solution.canPartitionGrid(grid);
    return 0;
}