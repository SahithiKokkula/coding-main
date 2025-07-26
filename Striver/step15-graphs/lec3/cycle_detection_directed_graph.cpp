#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    pair<vector<vector<int>>,int>adj_lst(){
        int n ,m;
        cin>>n>>m;
        int v ,u;
        vector<vector<int>>adjacency_list(n,vector<int>());
        for (int i = 0;i<m;i++){
            cin>>v>>u;
            adjacency_list[v].emplace_back(u);
        }
        return {adjacency_list,n};
    }

private:
    vector<int>khan_algorithm(vector<vector<int>>&adj_list,int n){
        vector<int>indegree(n,0);
        vector<int>result;
        for (auto it  : adj_list){
            for(auto itt : it){
                indegree[itt]++;
            }
        }
        queue<int>q;
        for(int i = 0;i<n;i++){
            if (indegree[i]==0 ){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            result.push_back(curr);
            q.pop();
            for(auto it : adj_list[curr]){
                indegree[it]--;
                if (indegree[it]== 0){
                    q.push(it);
                }
            }

        }
        return result;
    }
public:
    bool is_cycle(vector<vector<int>>&adj_lst,int n){
        return khan_algorithm(adj_lst,n).size() != n;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    auto pair_adj_n = solution.adj_lst();
    vector<vector<int>> adj_list = pair_adj_n.first;
    int n = pair_adj_n.second;
    bool result = solution.is_cycle(adj_list,n);
    cout<<endl;
    return 0;
}