#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string clearStars(string s) {
        map<char,vector<int>>mp;
        int n = s.size();
        vector<bool>del_char(n,0);
        for(int i = 0 ; i < n ;i++){
            if(s[i] == '*'){
                int idx = *(((*(mp.begin())).second).rbegin());
                if (((*(mp.begin())).second).size() == 1) mp.erase(mp.begin());
                else ((*(mp.begin())).second).pop_back();
                del_char[idx] = 1;
                del_char[i] = 1;
            }
            else{
                mp[s[i]].push_back(i);
            }
        }
        string ans = "";
        for(int i = 0 ; i < n ; i++){
            if (!del_char[i]){
                ans += s[i];
            }
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s = "aaba*";
    cout<<solution.clearStars(s);
    return 0;
}