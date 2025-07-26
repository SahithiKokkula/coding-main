#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        if(n < 3) return s;
        char last2 = s[0];
        char last1 = s[1];
        string ans = s.substr(0,2);
        for(int i = 2 ;i < n ; i++){
            if(last1 == last2 && last1 == s[i]){
               continue; 
            }
            else{
                ans += s[i];
                last2 = last1;
                last1 = s[i];
            }
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}