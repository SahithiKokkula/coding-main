#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool parseBoolExpr(string expression) {
        
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string expression = "!(&(f,t))";
    cout<<solution.parseBoolExpr(expression)?"true":"false";
    cout<<endl;
    return 0;
}