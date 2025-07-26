#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve() {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];

        unordered_set<int> st;
        st.insert(arr[0]);
        vector<int> used;
        used.push_back(arr[0]);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (st.find(arr[i]) == st.end()) {
                used.push_back(arr[i]);
            } else {
                st.erase(arr[i]);
                used.push_back(arr[i]);
                if (st.empty()) {
                    cnt++;
                    for(auto it:used){
                        st.insert(it);
                    }
                    used.clear();
                }
            }
        }

        cout << cnt << endl;
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


// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// void solve() {
//     int n;
//     cin >> n;

//     vector<int> a(n + 1), nextPos(n + 2), lastSeen(n + 2, n + 1);

//     for (int i = 1; i <= n; ++i) {
//         cin >> a[i];
//     }

//     for (int i = n; i >= 1; --i) {
//         nextPos[i] = lastSeen[a[i]];
//         lastSeen[a[i]] = i;
//     }

//     int pos = 1, segments = 0;
//     while (pos <= n) {
//         int end = pos;
//         while (true) {
//             int maxNext = 0;
//             for (int i = pos; i <= end; ++i) {
//                 maxNext = max(maxNext, nextPos[i]);
//             }
//             ++segments;
//             if (maxNext > n) break;
//             pos = end + 1;
//             end = maxNext;
//         }
//         break;
//     }

//     cout << segments << '\n';
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int tests;
//     cin >> tests;
//     while (tests--) {
//         solve();
//     }

//     return 0;
// }
