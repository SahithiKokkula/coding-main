#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    string removeOuterParentheses(string S) {
        string result;
        int balance = 0;
        int start = 0;
        
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '(') {
                balance++;
            } else {
                balance--;
            }
            
            if (balance == 0) {
                result += S.substr(start + 1, i - start - 1);
                start = i + 1;
            }
        }
        
        return result;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s = "(()())(())";
    cout<<solution.removeOuterParentheses(s)<<endl;
    return 0;
}