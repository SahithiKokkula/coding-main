#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int &val : a) cin >> val;

    int l = n, r = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            l = min(l, i);
            r = max(r, i);
        }
    }

    if (r - l + 1 <= x) 
        cout << "YES\n";
    else 
        cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) {
        solve();
    }

    return 0;
}
