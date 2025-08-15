#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;
        int se=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                cnt++;
            }
            else if(s[i]==')'){
                if(cnt<=0){
                    se++;
                }
                else{
                    cnt--;
                }
            }
        }
        return  cnt + se;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}