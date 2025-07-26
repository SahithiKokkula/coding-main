#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) cin >> arr[i];

        int cnt = 0, ans = 0;
        for(int i = 1; i < n; ++i){
            if(arr[i-1] < 2 * arr[i]){
                cnt++;
                if(cnt >= k) ans++;
            } else {
                cnt = 0;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
