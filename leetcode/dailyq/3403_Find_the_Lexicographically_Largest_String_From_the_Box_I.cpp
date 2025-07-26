#include<bits/stdc++.h>
using namespace std;
class Solution {

public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;
        int n = word.length();
        string res = "";
        for(int  i = 0 ; i < n ; i++){
            int len = min(n-i,n-numFriends+1);
            res = max(res,word.substr(i,len));
        }
        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string  word = "gggg";
    int numFriends = 4;
    cout<<solution.answerString(word,numFriends);
    return 0;
}
