// #include<bits/stdc++.h>
// using namespace std;
// void solve(){
//     int n;
//     cin>>n;
//     string arr;
//     cin>>arr;
//     long long ans = 0;
//     for(int i=1;i<=n;i++){
//         if (arr[i-1] == '0'){
//             arr[i-1] = '2';
//             ans += i;
//         }
//         int k = 2;
//         while(k*i-1 < n && arr[k*i-1] == '0' && arr[i-1] == '2'){
//             arr[i*k-1] = '2';
//             ans += i;
//             k++;
//         }
//     }
//     cout<<ans<<endl;
// }
// int main(){
//     int t;
//     cin>>t;
//     while(t--){
//         solve();
//     }
// }


#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string arr;
    cin >> arr;
    string marked(n,'1');
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == '0') {
            for(long long j = i+1;j<=n;j+=i+1){
                if (arr[j-1]=='1'){
                    break;
                }
                if(marked[j-1]=='0'){
                    continue;
                }
                marked[j-1]='0';
                ans +=i+1;
            }
        }
    }
    cout << ans << endl;
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