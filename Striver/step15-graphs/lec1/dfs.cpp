#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& adjacency_list, vector<int>& result, vector<int>& visited_array, int node ) {
        result.push_back(node);
        visited_array[node] = 1;
        for (auto it : adjacency_list[node]) {
            if (visited_array[it] == 0) {
                dfs(adjacency_list, result, visited_array, it);
            }
        }
        return;
    }

public:
    vector<int> dfs_graph(vector<vector<int>>& adjacency_list) {
        int n = adjacency_list.size();
        vector<int> visited_array(n, 0);
        vector<int> result;
        for(int i = 0 ; i< n; i++){
            if(!visited_array[i]){
                dfs(adjacency_list, result, visited_array,i);
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> adjacency_list = {{1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2}};
    Solution solution;
    vector<int> result = solution.dfs_graph(adjacency_list);
    for (auto it : result) {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}