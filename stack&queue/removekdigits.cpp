#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string stack = "";

        for (char digit : num) {
            while (!stack.empty() && k > 0 && stack.back() > digit) {
                stack.pop_back();
                k--;
            }
            stack.push_back(digit);
        }

        // If k > 0, remove remaining from end
        while (k > 0 && !stack.empty()) {
            stack.pop_back();
            k--;
        }

        // Remove leading zeros
        int start = 0;
        while (start < stack.size() && stack[start] == '0') {
            start++;
        }

        string result = stack.substr(start);
        return result.empty() ? "0" : result;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    return 0;
}