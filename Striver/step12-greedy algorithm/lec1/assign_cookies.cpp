#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int g_int = g.size(),s_int  = s.size();
        int l = 0;
        int r = 0;
        while( l < s_int || r < g_int){
            if (g[r]<=s[l]){
                r++;
            }
            l++;
        }
        return r;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int g_int,s_int;
    cin>>g_int>>s_int;
    vector<int>g(g_int);
    vector<int>s(s_int);
    for(int i=0;i<g_int;i++){
        cin>>g[i];
    }
    for(int i=0;i<s_int;i++){
        cin>>s[i];
    }
    int result = solution.findContentChildren(g,s);
    cout<<result;
    return 0;
}