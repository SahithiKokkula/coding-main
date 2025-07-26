#include<bits/stdc++.h>
using namespace std;
class kosaraju_algorithm{
private:
    void dfs_step_1(int i,  vector<vector<int>>&adj_list,vector<bool>&vis,stack<int>&st){
        vis[i] = 1;
        
        for(auto it :adj_list[i]){
            if(!vis[it]){
                dfs_step_1(it,adj_list,vis,st);
            }
        }
        st.push(i);
    }
private:
    stack<int> step_1(vector<vector<int>>&adj_list){
        int n = adj_list.size();
        vector<bool>vis(n,0);
        stack<int>st;
        for(int i = 0 ; i < n; i++){
            if(!vis[i]){
                dfs_step_1(i,adj_list,vis,st);
            }
        }
        return st;
    }
private:
    vector<vector<int>> step_2(int n, vector<vector<int>>&adj_list){
        vector<vector<int>>adj_Tlist(n);
        for(int i = 0 ; i < n ; i++){
            for(auto it: adj_list[i]){
                adj_Tlist[it].push_back(i);
            }
        }
        return adj_Tlist;
    }
private: 
    void dfs_step_3(int i ,vector<vector<int>>&adj_Tlist,vector<int>&ans,vector<bool>&vis){
        vis[i] = 1;
        ans.push_back(i);
        for(auto it :adj_Tlist[i]){
            if (!vis[it]){
                dfs_step_3(it,adj_Tlist,ans,vis);
            }
        }
    }
private:
    vector<vector<int>> step_3(int n, vector<vector<int>>&adj_Tlist,vector<vector<int>>&f_ans,stack<int>&st){
        vector<bool>vis(n,0);
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if (!vis[node]){
                vector<int>ans;
                dfs_step_3(node, adj_Tlist,ans,vis);
                f_ans.push_back(ans);
            }
            
        }
        return f_ans;
    }
public:
    vector<vector<int>>kosaraju_algo(vector<vector<int>>&adj_list){
        int n = adj_list.size();
        stack<int>st = step_1(adj_list);

        vector<vector<int>>adj_Tlist = step_2(n,adj_list);

        vector<vector<int>>ans;
        step_3(n,adj_Tlist,ans,st);

        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    kosaraju_algorithm solution;
    vector<vector<int>>adj_list = {{1},{2},{0,3},{4},{5,7},{6},{4,7},{}};
    vector<vector<int>>ans = solution.kosaraju_algo(adj_list);

    for(auto it:ans){
        for(auto itt:it){
            cout<<itt<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}