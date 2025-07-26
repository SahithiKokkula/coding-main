// #include<bits/stdc++.h>
// using namespace std;
// class Solution{
// public:
//     vector<pair<int,int>>generate_connections(vector<int>&districts,int n){
//         vector<pair<int,int>>connections;
//         int i = 0;
//         int j = 0;
//         int k = 1;
//         while (k<n){
//             if (districts[j]==districts[k]){
//                 k++;
//             }   
//             else{
//                 connections.emplace_back(j+1,k+1);
//                 j++;
//             }
//         }
//         return connections;
//     }
// };
// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     Solution solution;
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         vector<int> disricts(n);
//         bool check = 0;
//         for(int i = 0; i < n; i++){ 
//             cin >> disricts[i];
//             if (i > 0 && disricts[i-1] != disricts[i]) check = 1;
//         }
        
//         if (!check){
//             cout<<"NO"<<endl;
//         }
//         else{
//             vector<pair<int,int>> result = solution.generate_connections(disricts,n);
//             cout<<"YES"<<endl;
//             for(auto it : result){
//                 cout<<it.first<<" "<<it.second<<" "<<endl;
//             }
//         }

//     }
//     return 0;
// }



#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    // Check if all are the same
    bool all_same = true;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[0]) {
            all_same = false;
            break;
        }
    }
    if (all_same) {
        cout << "NO\n";
        return;
    }

    // Find v such that a[v] != a[0]
    int u = 0;
    int v = -1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[u]) {
            v = i;
            break;
        }
    }

    vector<pair<int, int>> edges;

    // Connect all nodes not in u's gang to u
    for (int i = 0; i < n; ++i) {
        if (i != u && a[i] != a[u]) {
            edges.emplace_back(u + 1, i + 1);
        }
    }

    // Connect remaining nodes (same as u's gang) to v
    for (int i = 0; i < n; ++i) {
        if (i != u && a[i] == a[u]) {
            edges.emplace_back(v + 1, i + 1);
        }
    }

    cout << "YES\n";
    for (auto &p : edges) {
        cout << p.first << " " << p.second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}