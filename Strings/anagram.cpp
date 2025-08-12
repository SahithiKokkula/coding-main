#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int a[26] = {0};

        for(int i = 0; i < s.size(); i++){
            a[(int)s[i] - 97] += 1;
            a[(int)t[i] - 97] -= 1;
        }

        for(int i : a){
            if (i != 0) return false;
        }

        return true;
        
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}