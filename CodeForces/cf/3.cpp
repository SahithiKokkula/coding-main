
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void solve(){
        int n;
        cin >> n;
        vector<int> a(n);
        int num;
        for (int i = 0; i < n; i++) {
            cin>>num;
            a[i] = num;
        }

        long long c = 0;

        for (int k = 2; k < n; k++) {
            int target = max(a[k], a[n - 1] - a[k]);

            int lo = 0, hi = k - 1;
            while (lo < hi) {
                if (a[lo] + a[hi] > target) {
                    c += (hi - lo);
                    hi = hi - 1;
                } else {
                    lo = lo + 1;
                }
            }
        }

        cout <<c<<endl;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int t;
    cin>>t;
    while (t--)
    {
        solution.solve();
    }
    
    return 0;
}