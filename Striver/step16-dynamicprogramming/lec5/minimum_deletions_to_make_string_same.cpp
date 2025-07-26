#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int sol3(int n1, int n2, string &text1, string &text2) {
        vector<vector<int>>dp(n1,vector<int>(n2,0));
        vector<int>prev(n2,0);
        prev[0] = (text1[0] == text2[0]) ? 1 : 0;
        for (int j = 1; j < n2; j++) {
            prev[j] = (text1[0] == text2[j]) ? 1 : prev[j-1];
        }
        for(int i = 1 ; i < n1 ;i++){
            vector<int>temp(n2,0);
            temp[0] = (text1[i] == text2[0]) ? 1 : prev[0];
            for(int j = 1 ; j < n2 ;j++){
                if(text1[i] == text2[j]) temp[j]++;
                if (text1[i] == text2[j]) {
                    temp[j] = 1 + prev[j-1];
                } else {
                    temp[j] = max(prev[j],temp[j-1]);
                }
            }
            prev = temp;
        }    
        return prev[n2-1];
    }
public:
    int minDistance(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        return n1 + n2 - sol3(n1,n2,text1,text2)*2;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string text1 = "psnw";
    string text2 = "vozsh";
    cout<<solution.minDistance(text1,text2)<<endl;
    return 0;
}