#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0; // max depth found
        int c = 0;    // current depth

        for (char ch : s) {
            if (ch == '(') {
                c++;
                maxi = max(maxi, c); // update max depth
            } 
            else if (ch == ')') {
                c--;
            }
        }
        return maxi;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}