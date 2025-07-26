#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0;
        int curr = 0;
        for(char it : s){
            if(it == '('){
                curr++;
                maxi = max(maxi, curr);
            } else if(it == ')'){
                curr--;
            }
        }
        return maxi;

    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s = "(1+(2*3)+((8)/4))+1";
    cout<<solution.maxDepth(s)<<endl;
    return 0;
}