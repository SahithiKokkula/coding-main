#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void solve(){
        int n;
        cin>>n;
        vector<int>arr(n,0);
        int num;
        for(int i =0 ; i < n ; i++){
            cin>>num;
            arr[i] = num;
        }
        long mincost = INT_MAX;
        int i = 0;
        int j = 0;
        while(j<n){
            if (j + 1 < n && arr[j+1] == arr[i]){
                j++;
            }
            else{
                mincost = min(mincost,(long)arr[i] * (long)(i + (n - 1 - j)));
                i = j+1;
            }
        }
        cout<<mincost<<endl;
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



#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int64_t mcost = LLONG_MAX;

        for (int i = 0; i < n;) {
            int j = i;
            while (j + 1 < n && a[j + 1] == a[i]) {
                ++j;
            }

            int64_t cst = a[i] * (i + (n - 1 - j));
            mcost = min(mcost, cst);

            i = j + 1;
        }

        cout << mcost << '\n';
    }

    return 0;
}
