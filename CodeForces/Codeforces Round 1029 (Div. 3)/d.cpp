#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPossible(int a, int b, int c) {
    for (int x = 0; x <= c / a; ++x) {
        int rem = c - a * x;
        if (rem % b == 0) return true;  // y = rem / b is an integer
    }
    return false;
}


public:
    void solve() {
        int n;
        cin >> n;
        bool check = true;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            if (!isPossible(i + 1, n - i, num)) {
                // cout<<i+1<<" "<<n-i<<" "<<" ";
                check = false;
            }
        }
        cout << (check ? "YES" : "NO") << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int t;
    cin >> t;
    while (t--) {
        solution.solve();
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;



// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<long long> arr(n);
//         for (int i = 0; i < n; i++)
//             cin >> arr[i];

//         long long d = arr[1] - arr[0];
//         bool check = true;

//         for (int i = 2; i < n; i++) {
//             if (arr[i] - arr[i - 1] != d) {
//                 check = false;
//                 break;
//             }
//         }

//         if (!check) {
//             cout << "NO\n";
//             return;
//         }

//         long long c = arr[0] - d;
//         if (c < 0 || c % (n + 1)) {
//             cout << "NO\n";
//             return;
//         }

//         long long y = c / (n + 1);
//         long long x = y + d;

//         if (x < 0 || y < 0) {
//             cout << "NO\n";
//             return;
//         }

//         cout << "YES\n";
//     }

//     return 0;
// }
