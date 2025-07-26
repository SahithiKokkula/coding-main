#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int minabsdiff(vector<vector<int>>&grid,int i ,int j,int k){
        vector <int> st;
        int n = 0;
        for(int p = i ; p <i+k;p++){
            for(int q = j ; j <j+k ;j++){
                st.push_back(grid[p][q]);
                n++;
            }
        }
        sort(st.begin(),st.end());
        int mini = INT_MAX;
        for(int i = 0 ; i < n-1 ; i++){
            mini = min(mini , abs(st[i]-st[i+1]));
        }
        return mini;
    }
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>ans(m-k+1,vector<int>(n-k+1));
        for(int i = 0 ; i < m-k+1 ;i++){
            for(int j = 0 ; j < n-k+1;j++){
                ans[i][j] = minabsdiff(grid,i,j,k);
            }
        }
        return ans;
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}