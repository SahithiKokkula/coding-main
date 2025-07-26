#include<bits/stdc++.h>
using namespace std;

long long calculate_t1(string s, long long n, long long x, long long k) {
    int check = -1;
    long long time = 0;
    for (long long i = 0; i < n; i++) {
        if (s[i] == 'L') x--;
        else x++;
        time++;
        if (x == 0) {
            check = 1;
            break;
        }
        if (time > k) {
            break;
        }
    }
    if (check == 1) return time;
    return check;
}

long long calculate_t2(string s, long long n, long long k, long long t1) {
    int check = -1;
    long long time = 0;
    long long x = 0;
    for (long long i = 0; i < n; i++) {
        if (s[i] == 'L') x--;
        else x++;
        time++;
        if (x == 0) {
            check = 1;
            break;
        }
        if (time + t1 > k) {
            break;
        }
    }
    if (check == 1) return time;
    return check;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, x, k;
        cin >> n >> x >> k;
        string s;
        cin >> s;
        long long t1 = calculate_t1(s, n, x, k);
        if (t1 == -1) {
            cout << 0 << endl;
        } else {
            long long t2 = calculate_t2(s, n, k, t1);
            if (t2 == -1) {
                cout << 1 << endl;
            } else {
                cout << 1 + (k - t1) / t2 << endl;
            }
        }
    }
    return 0;
}