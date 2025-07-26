#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string res = "";
        int cnt = 0;
        
        for(int i = n-1 ; i >= 0 ;i--){
            if(s[i] == ' '){
                if (s.substr(i+1,cnt) != ""){
                    res = res + s.substr(i+1,cnt) + ' ' ;
                    cnt = 0;
                }
                
                continue;
            }

            cnt++;
        }
        return string(res.begin(),res.end()-1) ;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s = "    the sky is     blue     ";
    cout<<solution.reverseWords(s)<<endl;
    return 0;
}