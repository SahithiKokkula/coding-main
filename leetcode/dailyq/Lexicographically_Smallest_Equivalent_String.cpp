#include<bits/stdc++.h>
using namespace std;

class disjointSet {
    vector<int> parent;
public:
    disjointSet(int n) {
        parent.resize(n+1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findUParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return;
        if (ulp_u > ulp_v) {
            parent[ulp_u] = ulp_v;
        } else if (ulp_v > ulp_u) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        disjointSet d(26);
        int i = 0;
        while(s1[i] != '\0'){
            d.unionByRank(s1[i] - 'a',s2[i] - 'a');
            i++;
        }
        string ans = "";
        i = 0;
        while(baseStr[i] != '\0'){
            ans += d.findUParent(baseStr[i++] - 'a') + 'a';
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s1 = "leetcode", s2 = "programs", baseStr = "sourcecode";
    cout<<solution.smallestEquivalentString(s1,s2,baseStr);

    return 0;
}