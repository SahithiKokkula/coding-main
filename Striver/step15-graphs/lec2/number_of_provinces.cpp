#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        int n = isConnected.size();
        visited[i] = true;
        for (int j = 0; j < n; ++j) {
            if (isConnected[i][j] == 1 && !visited[j]) {
                dfs(isConnected, visited, j);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++count;
                dfs(isConnected, visited, i);
            }
        }
        return count;
    }
};
int main(){
    int n, m;
    cin >> n >> m;
    int v, u;
    vector<vector<int>> adjacency_list(n, vector<int>());
    for (int i = 0; i < m; i++) {
        cin >> v >> u;
        adjacency_list[v].emplace_back(u);
        adjacency_list[u].emplace_back(v);
    }
    Solution solution;
    int result = solution.findCircleNum(adjacency_list);
    cout << result << endl;
    return 0;
}