#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        
        stack<char> st;
        string result;
        int minChar = 0;
        
        for (char c : s) {
            st.push(c);
            freq[c - 'a']--;
            
            while (minChar < 26 && freq[minChar] == 0) {
                minChar++;
            }
            
            while (!st.empty() && st.top() - 'a' <= minChar) {
                result.push_back(st.top());
                st.pop();
                
                while (minChar < 26 && freq[minChar] == 0) {
                    minChar++;
                }
            }
        }
        
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        
        return result;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s = "bdda";
    cout<<solution.robotWithString(s);
    return 0;
}