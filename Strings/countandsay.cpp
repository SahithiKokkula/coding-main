#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    string RLE(const string& s) {
        string ans = "";
        int count = 1;
        for (int i = 1; i <= s.size(); i++) {
            if (i < s.size() && s[i] == s[i - 1]) {
                count++;
            } else {
                ans += to_string(count);
                ans += s[i - 1];
                count = 1;
            }
        }
        return ans;
    }

public:
    string countAndSay(int n) {
        string c = "1";
        for (int i = 1; i < n; i++) {
            c = RLE(c);
        }
        return c;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}