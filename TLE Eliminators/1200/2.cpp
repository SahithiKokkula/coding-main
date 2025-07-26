#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> arr(n);
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
        }

        long long k = 1;
        bool found = false;
        while (true) {
            set<long long> st;
            for (long long i = 0; i < n; i++) {
                st.insert(arr[i] % k);
                if (st.size() > 2) {
                    break; // No need to continue if more than 2 remainders
                }
            }
            if (st.size() == 2) {
                found = true;
                break; // Found the correct k
            }
            k = k * 2; // Double k for the next iteration

            // Exit condition to prevent infinite loop
            if (k > 1e18) {
                break; // Arbitrary large limit to prevent infinite loop
            }
        }

        if (found) {
            cout << k << endl;
        } else {
            cout << -1 << endl; // No valid k found
        }
    }
    return 0;
}