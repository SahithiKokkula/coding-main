#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0; 
        int n = s.length();
        int j = 0;
        int max_len = INT_MIN;
        map<int,int>chars;
        while(i <= j && j < n){
            if(chars.find(s[j]) != chars.end()){
                if(chars[s[j]] >= i){
                    i = chars[s[j]] + 1;
                }
            }
            max_len = max(max_len, j - i + 1);
            chars[s[j]] = j;
            j ++;
        }
        return max_len == INT_MIN ? 0 : max_len;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s = "abcabcbb";
    cout<<solution.lengthOfLongestSubstring(s);
    return 0;
}