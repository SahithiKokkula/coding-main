#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    vector<int>khan_algorithm(vector<vector<int>>&adj_list,int n){
        vector<bool>visited(n,0);
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
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>result;
        vector<vector<int>>adj_list(n,vector<int>());
        vector<int>outgoing(n);
        queue<int>q;
        for(int i = 0; i<n;i++){
            for (auto itt : graph[i]){
                adj_list[itt].emplace_back(i);
                outgoing[i]++;
            }
            if (outgoing[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            result.push_back(curr);
            q.pop();
            for(auto it : adj_list[curr]){
                outgoing[it]--;
                if (outgoing[it] == 0){
                    q.push(it);
                }
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<vector<int>>graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int>result  = solution.eventualSafeNodes(graph);
    for(auto it : result){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}