#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>map1(128,-1);
        vector<int>map2(128,-1);
        int n = s.length();
        for(int i = 0 ; i < n;i++){
            if(map1[s[i] - '!'] == -1 && map2[t[i] - '!'] == -1){
                map1[s[i] - '!'] = t[i];
                map2[t[i] - '!'] = s[i];
            }
            else if(map1[s[i]-'!'] == t[i] && map2[t[i]-'!'] == s[i]){
                continue;
            }
            else{
                return 0;
            }
        }
        return 1;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s = "egg";
    string t = "add";
    cout<<(solution.isIsomorphic(s,t)?"YES":"NO")<<endl;
    return 0;
}