#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int L = count(s.begin(), s.end(), 'L');
    int I = count(s.begin(), s.end(), 'I');
    int T = count(s.begin(), s.end(), 'T');
    
    // Check if all characters are the same
    if (L == n || I == n || T == n) {
        if (n % 3 == 0 && L == n / 3 && I == n / 3 && T == n / 3) {
            cout << 0 << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }
    
    // Check possible k
    bool possible = false;
    int target = -1;
    for (int k = max({L, I, T}); k <= n + 2*n; ++k) {
        int m = 3*k - n;
        if (m < 0) continue;
        if (m > 2*n) break;
        if ((n + m) % 3 != 0) continue;
        target = k;
        possible = true;
        break;
    }
    if (!possible) {
        cout << -1 << endl;
        return;
    }
    
    int delta_L = target - L;
    int delta_I = target - I;
    int delta_T = target - T;
    
    vector<int> steps;
    vector<char> current(s.begin(), s.end());
    
    while (delta_L > 0 || delta_I > 0 || delta_T > 0) {
        int best_idx = -1;
        char best_char = ' ';
        int max_delta = -1;
        
        for (int i = 0; i < (int)current.size() - 1; ++i) {
            char a = current[i];
            char b = current[i+1];
            if (a == b) continue;
            
            char x;
            if ((a == 'L' && b == 'I') || (a == 'I' && b == 'L')) x = 'T';
            else if ((a == 'L' && b == 'T') || (a == 'T' && b == 'L')) x = 'I';
            else x = 'L';
            
            int current_delta;
            if (x == 'L') current_delta = delta_L;
            else if (x == 'I') current_delta = delta_I;
            else current_delta = delta_T;
            
            if (current_delta > max_delta) {
                best_idx = i;
                best_char = x;
                max_delta = current_delta;
            } else if (current_delta == max_delta && best_idx == -1) {
                best_idx = i;
                best_char = x;
                max_delta = current_delta;
            }
        }
        
        if (best_idx == -1) {
            cout << -1 << endl;
            return;
        }
        
        steps.push_back(best_idx + 1); // 1-based position
        current.insert(current.begin() + best_idx + 1, best_char);
        
        if (best_char == 'L') delta_L--;
        else if (best_char == 'I') delta_I--;
        else delta_T--;
    }
    
    cout << steps.size() << endl;
    for (int pos : steps) {
        cout << pos << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}