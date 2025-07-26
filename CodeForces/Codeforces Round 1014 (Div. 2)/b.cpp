#include<bits/stdc++.h>
using namespace std;

bool checknswap(string *a, string *b, int i, int n) {
    if ((i & 1) == 0) { // even index
        for (int j = 1; j < n; j += 2) {
            if ((*b)[j] == '0') {
                swap((*b)[j], (*a)[i]);
                return true;
            }
        }
    } else { // odd index
        for (int j = 0; j < n; j += 2) {
            if ((*b)[j] == '0') {
                swap((*b)[j], (*a)[i]);
                return true;
            }
        }
    }
    return false;
}

bool check(string a, string b, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
            if (!checknswap(&a, &b, i, n)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        cout << (check(a, b, n) ? "YES" : "NO") << endl;
    }
    return 0;
}