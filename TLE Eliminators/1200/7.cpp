// #include<bits/stdc++.h>
// using namespace std;

// void solve(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>>arr(m,vector<int>(n));
//     for(int i=0;i<n;i++){
//         long summ = 0;
//         for(int j=0;j<m;j++){
//             cin>>arr[j][i];
//         }
//     }
//     for(int i=0;i<m;i++){
//         sort(arr[i].begin(),arr[i].end());
//     }
//     vector<long>sumarr(n);
//     for(int i=0;i<n;i++){
//         long summ = 0;
//         for(int j=0;j<m;j++){
//             summ += arr[j][i];
//         }
//         sumarr[i] = summ;
//     }
//     long long total = 0;
//     for (int i = 0;i<n;i++){
//         total +=  i*sumarr[i]  - (n-1-i)*sumarr[i];
//     }
//     cout<<total<<endl;
// }
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
// }

#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> columns(m, vector<int>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> columns[j][i];
        }
    }
    long long total = 0;
    for(auto& col : columns) {
        sort(col.begin(), col.end());
        long long sum_so_far = 0;
        for(int i = 0; i < n; ++i) {
            total += (long long) col[i] * i - sum_so_far;
            sum_so_far += col[i];
        }
    }
    cout << total << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
