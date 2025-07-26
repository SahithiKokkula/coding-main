#include <bits/stdc++.h>
using namespace std;

long long compute_s_max(long long m, long long L) {
    long long s1 = (m + 1) / 2; // Floor division of (m+1)/2
    long long s2 = (L * (m + 1)) / (L + 1); // long longeger division for s2
    long long s_max = max(s1, s2);
    s_max = min(s_max, m); // Ensure it does not exceed m
    return s_max;
}

bool is_feasible(long long L, long long n, long long m, long long k) {
    long long s_max = compute_s_max(m, L);
    long long total = (long long)n * s_max;
    return total >= k;
}

long long solve(long long n, long long m, long long k) {
    long long low = 1, high = m;
    long long ans = m; // Initialize with maximum possible value
    while (low <= high) {
        long long mid = (low + high) / 2;
        if (is_feasible(mid, n, m, k)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, m, k;
        cin >> n >> m >> k;
        cout << solve(n, m, k) << endl;
    }
    return 0;
}