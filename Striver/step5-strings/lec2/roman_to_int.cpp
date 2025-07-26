#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    map<char,int>symbols = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000},{'z',10000}};
public:
    int romanToInt(string s) {
        int total = 0;
        int prev = 0;

        for(int i = s.size() - 1; i >= 0; i--) {
            int curr = symbols[s[i]];
            if(curr < prev) total -= curr;
            else total += curr;
            prev = curr;
        }
        return total;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s = "MCMXCIV";
    cout<<solution.romanToInt(s)<<endl;
    return 0;
}