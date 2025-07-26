#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    
    while (t--) {
        cin >> n;
        unordered_map<int, int> freq1, freq2;
        int num, c1 = 0, c2 = 0;
        bool valid1 = true, valid2 = true;

        for (int i = 0; i < n; i++) {
            cin >> num;
            freq1[num]++;
        }
        for (auto& p : freq1) {
            if (p.second % 2 != 0) {
                valid1 = false;
                break;
            }
            c1++;
        }

        for (int i = 0; i < n; i++) {
            cin >> num;
            freq2[num]++;
        }
        for (auto& p : freq2) {
            if (p.second % 2 != 0) {
                valid2 = false;
                break;
            }
            c2++;
        }
        
        if (valid1 && valid2) {
            if ((c1 > 2) || (c1 == 2 && c2 == 2)) {
                cout << "YES"<<endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}