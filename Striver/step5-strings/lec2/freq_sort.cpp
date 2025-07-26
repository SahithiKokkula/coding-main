#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    vector<int> freq;

    int conv(char it) {
        if (it >= '0' && it <= '9') return it - '0';
        else if (it >= 'a' && it <= 'z') return it - 'a' + 10;
        else if (it >= 'A' && it <= 'Z') return it - 'A' + 36;
        return -1;
    }

public:
    string frequencySort(string s) {
        freq.assign(62, 0);  // 10 digits + 26 lowercase + 26 uppercase

        for (char it : s) {
            int i = conv(it);
            if (i != -1) freq[i]++;
        }

        sort(s.begin(), s.end(), [this](char a, char b) {
            return freq[conv(a)] > freq[conv(b)];
        });

        return s;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution solution;
    string s = "abbshbjedx";
    cout << solution.frequencySort(s) << '\n';

    return 0;
}
