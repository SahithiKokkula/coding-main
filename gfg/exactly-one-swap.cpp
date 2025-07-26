#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countStrings(string &s) {
        vector<int>freq(26,0);
        int l = s.length();
        int ans = 0;
        bool check = false;
        vector<int>f(l);
        for(int i = l - 1; i >= 0; i--){
            f[i] = freq[s[i] - 'a'];
            freq[s[i] - 'a']++;
        }
        for(int i = 0; i < l ;i++){
            if(f[i]>1) check = true;
            ans += ((l - 1 - i) - f[i]);
        }
        if(check) ans += 1;
        return ans;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s = "geek";
    cout<<solution.countStrings(s);
    return 0;
}