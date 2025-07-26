#include <iostream>
using namespace std;
class solution{
private: 
    int bit_high(long long x) {
    if (x == 0) return -1; 
    return 63 - __builtin_clzll(x);
}
public:
void solve() {
    long long x;
    cin >> x;
    int k = bit_high(x);
    long long res = 2LL * k + 3;
    cout << res << "\n";
}};

int main() {
    int t;
    cin >> t;
    solution sol;
    while (t--) {
        sol.solve();
    }
    return 0;
}
