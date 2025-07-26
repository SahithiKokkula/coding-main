#include<bits/stdc++.h>
using namespace std;
class Solution{
public: 
    int minDeletion(string s, int k) {
        vector<int>freq(26,0);
        for(auto it:s){
            freq[it-'a']++;
        }
        sort(freq.begin(),freq.end());
        int cnt = 0;
        for(int i = 25-k;i>=0;i--){
            cnt += freq[i];
        }
        return cnt;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s = "abc";
    int k = 2;
    cout<<solution.minDeletion(s,k)<<endl;
    return 0;

}