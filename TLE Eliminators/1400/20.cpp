#include<bits/stdc++.h>
using namespace std;
struct cmp {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        if (a.second == b.second)
            return a.first < b.first;  // higher val first if freq equal
        return a.second < b.second;  // higher freq first
    }
};
class Solution{
public:
    void solve(){
        int n,k;
        cin>>n>>k;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        int num;
        for(int i = 0 ; i < n ; i++){
            cin>>num;
            int val = 0;
            if(num < k){
                val = (num + k) % k;
            }
            else if(num > k){
                val = k - (num % k);
            }
            if(val != 0){

            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int t;
    cin>>t;
    while(t--){
        solution.solve();
    }
    return 0;
}