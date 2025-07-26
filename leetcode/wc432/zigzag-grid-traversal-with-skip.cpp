#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        bool way = 0; // 0 -> left to right       1 ->  right to left
        bool skip = 0; // 1 -> skip           0 -> print
        vector<int>ans;
        for(int i = 0 ;i < m ; i ++){
            if (way == 0){
                for(int j = 0 ; j < n; j ++){
                    if (!skip) ans.push_back(grid[i][j]);
                    skip = !skip;
                }
                way = !way;
            }
            else{
                for(int j = n - 1 ; j >= 0; j --){
                    if (!skip) ans.push_back(grid[i][j]);
                    skip = !skip;
                }
                way = !way;
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