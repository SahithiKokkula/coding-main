#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    string infixToPostfix(string infix){
        int n = infix.length();
        map<char,int>priority = {{'^', 3}, {'*',2},{'/',2},{'+',1},{'-',1},{'(',0},{')',0}};
        stack<char>st;
        string postfix ="";
        for(int i = 0 ; i < n ; i++){
            char currChar = infix[i];
            int currPriority = priority.find(currChar) != priority.end() ? priority[currChar] : -1;
            if(currPriority == -1){
                postfix+= currChar;
            }
            else if(currPriority == 0){
                if(currChar == '('){
                    st.push(currChar);
                }
                else{
                    while(st.top() != '('){
                        postfix+=st.top();
                        st.pop();
                    }
                    st.pop();
                }
            }
            else{
                int lastele = st.empty() ? -1 : priority[st.top()];
while (!st.empty() && (
    (priority[st.top()] > currPriority) || 
    (priority[st.top()] == currPriority && currChar != '^') // <-- Fix here
)){
    postfix += st.top();
    lastele = st.empty() ? -1 : priority[st.top()];  // ❌ This is useless
    st.pop();
}
st.push(currChar);
            }
        }
        while(!st.empty()){
            postfix += st.top();
            st.pop();
        }
        return postfix;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s = "h^m^q^(7-4)";
    cout<<solution.infixToPostfix(s);
    return 0;
}