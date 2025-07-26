#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        stack<pair<int,int>>q;
        int n = color.size();
        for(int i = 0 ; i < n ;i++){
            pair<int,int>curr = {color[i],radius[i]};
            if (!q.empty() && q.top() == curr){
                q.pop();
            }
            else{
                q.push(curr);
            }
        }
        int cnt = 0;
        while (!q.empty()){
            cnt++;
            q.pop();
        }
        return cnt;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>color = {1,2,2,1};
    vector<int>radius = {1,2,2,1};
    cout<<solution.findLength(color,radius);
    return 0;
}