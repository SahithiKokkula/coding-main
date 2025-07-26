#include<bits/stdc++.h>
using namespace std;
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    long long calculateScore(string s) {
        int n = s.size();
        vector<bool> marked(n, false);
        unordered_map<char, vector<int>> charIndices;
        long long score = 0;

        for (int i = 0; i < n; ++i) {
            if (!marked[i]) {
                char current = s[i];
                char mirror = 'a' + (25 - (current - 'a'));
                if (charIndices.find(mirror) != charIndices.end() && !charIndices[mirror].empty()) {
                    int j = charIndices[mirror].back();
                    if (!marked[j]) {
                        marked[j] = true;
                        marked[i] = true;
                        score += i - j;
                        charIndices[mirror].pop_back();
                        continue;
                    }
                }
                charIndices[current].push_back(i);
            }
        }
        return score;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s = "aczzx";
    cout<<solution.calculateScore(s);
    return 0;
}