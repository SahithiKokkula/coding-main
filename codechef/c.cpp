// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
//     void solve(){
//         int n ,c;
//         cin>>n>>c;
//         vector<int>a(n);
//         vector<int>b(n);
//         int num;
//         for(int i = 0 ; i < n ; i++){
//             cin>>num;
//             a[i] = num;
//         }
//         for(int i = 0 ; i < n ; i++){
//             cin>>num;
//             b[i] = num;
//         }
//         map<int,int>mp;
//         for(int i = 0 ; i < n ;i++){
//             if (mp.find(a[i]) == mp.end()){
//                 mp[a[i]] = b[i];
//             }
//             else{
//                 mp[a[i]] = min(mp[a[i]] , b[i]);
//             }
//         }

//         int Y = 0;
//         int X = 0;
//         for(auto it: mp){
//             X++;
//             Y+=it.second;
//         }
//         int cost = c*X-Y;
//         cout<<max(0,cost)<<endl;
//     }
// };

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     Solution solution;
//     int t;
//     cin>>t;
//     while(t--){
//         solution.solve();

//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve() {
        int n, c;
        cin >> n >> c;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(a[i]) == mp.end()) {
                mp[a[i]] = b[i];
            } else {
                mp[a[i]] = min(mp[a[i]], b[i]);
            }
        }
        
        vector<int> costs;
        for (auto &it : mp) {
            costs.push_back(it.second);
        }
        
        sort(costs.begin(), costs.end());
        
        long long total_cost = 0;
        long long max_value = 0;
        for (int k = 1; k <= costs.size(); k++) {
            total_cost += costs[k - 1];
            long long current_value = (long long)c * k - total_cost;
            if (current_value > max_value) {
                max_value = current_value;
            }
        }
        
        cout << max(0LL, max_value) << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int t;
    cin >> t;
    while (t--) {
        solution.solve();
    }
    return 0;
}