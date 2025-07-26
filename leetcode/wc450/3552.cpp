// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
// private:
//     int sol(int i ,int j ,int m, int n ,vector<string>&matrix,unordered_map<char,vector<pair<int,int>>>&portals,unordered_map<char,bool>visited,vector<vector<bool>>&vis){
//         if(i == m-1 && j == n-1){
//             return 0;
//         }
//         if(vis[i][j] == 1) return INT_MAX;
//         vis[i][j] = 1;
//         vector<vector<int>>dir = {{1,0},{-1,0},{0,-1},{0,1}};
        
//         int mini = INT_MAX;
//         if (matrix[i][j] >= 'A' && matrix[i][j] <= 'Z' ) {
//             if(visited[matrix[i][j]] == 0 && portals[matrix[i][j]].size() == 2){
//                 int newi;
//                 int newj;
//                 if(i == portals[matrix[i][j]][0].first && j == portals[matrix[i][j]][0].second){
//                     newi = portals[matrix[i][j]][1].first;
//                     newj = portals[matrix[i][j]][1].second;
//                 }
//                 else{
//                     newi = portals[matrix[i][j]][0].first;
//                     newj = portals[matrix[i][j]][0].second;
//                 }
//                 visited[matrix[i][j]] = 1;
//                 mini = min(mini , 0 + sol(newi,newj,m,n,matrix,portals,visited,vis));
//                 visited[matrix[i][j]] = 0;
//             }
//         }
//         for(int k = 0 ; k < 4 ;k++){
//             int ni = i + dir[k][0];
//             int nj = j + dir[k][1];
//             if(ni>=0 && nj>=0 && ni < m && nj <n && matrix[ni][nj] != '#'){
//                 int steps = sol(ni,nj,m,n,matrix,portals,visited,vis);
//                 if(steps != INT_MAX) {
//                     mini = min(mini , 1 + steps);
//                 }
//             }
//         }
        
//         return mini;
//     }
// public:
//     int minMoves(vector<string>& matrix) {
//         unordered_map<char,vector<pair<int,int>>>portals;
//         unordered_map<char,bool>visited;
//         int m = matrix.size();
//         int n = matrix[0].size();
//         for(int i = 0 ; i < m ; i++){
//             for(int j = 0 ; j < n ;j++){
//                 if (matrix[i][j] <= 'Z' && matrix[i][j] >='A'){
//                     portals[matrix[i][j]].push_back({i,j});
//                     visited[matrix[i][j]] = 0;
//                 }
//             }
//         }
//         vector<vector<int>>memo(m,vector<int>(n,-1));
//         vector<vector<bool>>vis(m,vector<bool>(n,0));
//         int moves = sol(0,0,m,n,matrix,portals,visited,vis);
//         return  moves == INT_MAX ? -1 : moves;
//     }
// };

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     Solution solution;
//     vector<string>matrix = {"..","HA",".C","A."};
//     cout<<solution.minMoves(matrix);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<string>& matrix) {
        int m = matrix.size();
        if (m == 0) return -1;
        int n = matrix[0].size();
        
        // Collect portal positions
        unordered_map<char, vector<pair<int, int>>> portals;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char c = matrix[i][j];
                if (c >= 'A' && c <= 'Z') {
                    portals[c].emplace_back(i, j);
                }
            }
        }
        
        // Assign a unique bit index for each portal letter
        unordered_map<char, int> portalIndex;
        int P = 0;
        for (auto& kv : portals) {
            portalIndex[kv.first] = P++;
        }
        
        // Start/end blocked?
        if (matrix[0][0] == '#' || matrix[m-1][n-1] == '#') {
            return -1;
        }
        
        // BFS with state (i, j, mask)
        int maxMask = 1 << P;
        vector<vector<vector<bool>>> visited(
            m, vector<vector<bool>>(n, vector<bool>(maxMask, false))
        );
        
        queue<tuple<int,int,int>> q;
        q.emplace(0, 0, 0);
        visited[0][0][0] = true;
        int steps = 0;
        vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto state = q.front();
                q.pop();
                int i = get<0>(state);
                int j = get<1>(state);
                int mask = get<2>(state);

                if (i == m-1 && j == n-1)
                    return steps;
                
                char c = matrix[i][j];
                if (c >= 'A' && c <= 'Z' && portals[c].size() == 2) {
                    int bit = portalIndex[c];
                    if (!(mask & (1 << bit))) {
                        auto& pos = portals[c];
                        int ni = (i == pos[0].first && j == pos[0].second)
                                 ? pos[1].first : pos[0].first;
                        int nj = (i == pos[0].first && j == pos[0].second)
                                 ? pos[1].second : pos[0].second;
                        int newMask = mask | (1 << bit);
                        if (!visited[ni][nj][newMask]) {
                            visited[ni][nj][newMask] = true;
                            q.emplace(ni, nj, newMask);
                        }
                    }
                }
                
                for (auto& d : dirs) {
                    int ni = i + d.first;
                    int nj = j + d.second;
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && matrix[ni][nj] != '#') {
                        if (!visited[ni][nj][mask]) {
                            visited[ni][nj][mask] = true;
                            q.emplace(ni, nj, mask);
                        }
                    }
                }
            }
            ++steps;
        }
        
        return -1;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<string> matrix = {"..","HA",".C","A."};
    cout << solution.minMoves(matrix) << "\n";
    return 0;
}
