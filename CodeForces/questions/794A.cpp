#include<bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c;
    int n, num;
    cin >> a >> b >> c >> n;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> num;
        if (num > b && num < c) { 
            ans++;
        }
    }

    cout << ans;
    return 0;
}
