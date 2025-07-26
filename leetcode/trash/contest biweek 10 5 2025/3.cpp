#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    void dsf(int n, vector<vector<pair<int,int>>>&dj_list, int k, int t,vector<int>&result,int node,int tw){
        if (k == 0 && tw<t) {
            result[node] = max(result[node],tw);
        }
        for(auto it : dj_list[node]){
            dsf(n,dj_list,k-1,t,result,it.first,tw + it.second);
        }

    }
public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<vector<pair<int,int>>>adj_list(n,vector<pair<int,int>>());
        for(auto it : edges){
            adj_list[it[0]].push_back({it[1],it[2]});
        }
        vector<int>result(n);
        for(int i = 0 ; i < n ; i++){
            dsf(n,adj_list,k,t,result,i,0);
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int n = 3;
    vector<vector<int>>edges = {{0,1,6},{1,2,8}};
    int k = 1;
    int t = 6;
    cout<<solution.maxWeight(n,edges,k,t);
    return 0;
}