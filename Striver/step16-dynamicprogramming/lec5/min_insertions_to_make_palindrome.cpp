#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int sol3(int n,  string &s) {
        string text2 = "";
        for(int i = n-1;i>=0;i--){
            text2+=s[i];
        }
        vector<int>prev(n,0);
        prev[0] = (s[0] == text2[0]) ? 1 : 0;
        for (int j = 1; j < n; j++) {
            prev[j] = (s[0] == text2[j]) ? 1 : prev[j-1];
        }
        for(int i = 1 ; i < n ;i++){
            vector<int>temp(n,0);
            temp[0] = (s[i] == text2[0]) ? 1 : prev[0];
            for(int j = 1 ; j < n ;j++){
                if(s[i] == text2[j]) temp[j]++;
                if (s[i] == text2[j]) {
                    temp[j] = 1 + prev[j-1];
                } else {
                    temp[j] = max(prev[j],temp[j-1]);
                }
            }
            prev = temp;
        }    
        return prev[n-1];
    }
public:
    int minInsertions(string s) {
        int n = s.size();
        return n - sol3(n,s);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s = "zzazz";
    cout<<solution.minInsertions(s)<<endl;
    return 0;
}