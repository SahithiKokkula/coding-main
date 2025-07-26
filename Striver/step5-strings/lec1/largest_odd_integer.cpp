#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        for(int i = n-1;i >=0;i++){
            if ((num[i] - '0') & 1 == 1){
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string num = "35427";
    cout<<solution.largestOddNumber(num)<<endl;
    return 0;
}