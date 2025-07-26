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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>>adj_list(numCourses,vector<int>());
        for(auto it : prerequisites){
            adj_list[it[1]].emplace_back(it[0]);
        }
        vector<int>topo = khan_algorithm(adj_list , numCourses);
        return topo.size() == numCourses;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int numCources = 2;
    vector<vector<int>>prerequisites = {{1,0},{0,1}};
    cout<<solution.canFinish(numCources,prerequisites);
    cout<<endl;
    return 0;
}