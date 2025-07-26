#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int MOD = 1e9 + 7;

public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<int, int> mp;
        int n = points.size();

        for (auto& pt : points) {
            mp[pt[1]]++;
        }

        long long total = 0;

        for (auto& it : mp) {
            int sameY = it.second;
            int remPoints = n - sameY;
            if (sameY >= 2 && remPoints >= 2) {
                long long a = 1LL * sameY * (sameY - 1) / 2 % MOD;
                long long b = 1LL * remPoints * (remPoints - 1) / 2 % MOD;
                total = (total + a * b % MOD) % MOD;
            }
        }

        // divide total by 2 using modular inverse of 2
        long long inv2 = (MOD + 1) / 2;
        return (total * inv2) % MOD;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution solution;
    vector<vector<int>> points = {{37,39},{-19,62},{23,-48},{-61,62},{51,59}};
    cout << solution.countTrapezoids(points);  // Expected: 0
    return 0;
}
