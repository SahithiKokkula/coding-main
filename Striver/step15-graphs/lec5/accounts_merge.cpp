#include<bits/stdc++.h>
using namespace std;
class disjointSet{
    vector<int> rank,parent,size;
public:
    disjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }
    }

    int findUParent(int node){
        if (node == parent[node]){
            return node;
            return parent[node] = findUParent(parent[node]);
        }
    }

    void unionByRank(int u,int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }

    void unionBySize(int u,int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mailmap;
        int n = accounts.size();
        disjointSet ds(n);
        for(int i = 0 ;i < n; i++){
            for(int j = 1 ; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mailmap.find(mail)==mailmap.end()){
                    mailmap[mail] = i;
                }
                else{
                    int u = i;
                    int v = mailmap[mail];
                    ds.unionBySize(u,v);

                }
            }
        }
        vector<vector<string>>mails(n,vector<string>());
        for(auto it:mailmap){
            int uparent = ds.findUParent(it.second);
            string mail = it.first;
            mails[uparent].push_back(mail);
        }
        vector<vector<string>>result;
        for(int i = 0 ; i < n ; i++){
            if (mails[i].size()==0) continue;
            vector<string>temp;
            sort(mails[i].begin(),mails[i].end());
            temp.push_back(accounts[i][0]);
            for(auto it :mails[i]){
                temp.push_back(it);
            }
            result.push_back(temp);
        }
        return result;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<vector<string>>account = {{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};
    vector<vector<string>>result = solution.accountsMerge(account);
    for(auto it:result){
        for(auto itt:it){
            cout<<itt<<" ";
        }
        cout<<endl;
    }
    return 0;
}