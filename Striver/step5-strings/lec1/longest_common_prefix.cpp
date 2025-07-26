#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n1 = strs[0].size();
        int n = strs.size();
        int cnt = 0;
        while(cnt < n1){
            int tmp = 0;
            for(int i = 1 ; i < n ; i++){
                if (strs[0][cnt] == strs[i][cnt]){
                    tmp ++;
                }
            }
            if (tmp == n-1){
                cnt++;
                tmp = 0;
            }
            else{
                break;
            }
        }
        return strs[0].substr(0,cnt);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<string>strs = {"dog","racecar","car"};
    cout<<solution.longestCommonPrefix(strs)<<endl;
    return 0;
}