#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int maxFreqSum(string s) {
        vector<int>freq(26,0);
        for(auto it : s){
            freq[it - 'a']++;
        }
        int max1 = 0;
        int max2 = 0;
        for(int i = 0 ; i < 26;i++){
            if ( i + 'a' == 'a' || i + 'a' == 'e' || i + 'a' == 'i' || i + 'a' == 'o' || i+ 'a' == 'u'){
                max1 = max(max1,freq[i]);
            }
            else{
                max2 = max(max2,freq[i]);
            }
        }
        return max1 + max2;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s = "successes";
    cout<<solution.maxFreqSum(s);
    return 0;
}