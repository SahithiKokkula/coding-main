#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<char>st;
        map<char,char>bracketpair{{'(',')'},{'[',']'},{'{','}'}};
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }
            else if (!st.empty() && bracketpair[st.top()] == s[i]){
                st.pop();
            }
            else{
                return false;
            }
        }
        return st.empty();
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string  s = "([])";
    cout<<solution.isValid(s);
    return 0;
}