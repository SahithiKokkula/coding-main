#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int count0 = count(s.begin(), s.end(), '0');
    int count1 = n - count0;

    int minGoodPairs = max(count0, count1) - n / 2;

    int maxGoodPairs = (count0 / 2) + (count1 / 2);

    if (k >= minGoodPairs && k <= maxGoodPairs && (k - minGoodPairs) % 2 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
