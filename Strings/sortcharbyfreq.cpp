#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        priority_queue<pair<int, char>> maxHeap;
        for (auto& [c, count] : freq) {
            maxHeap.push({count, c});
        }

        string res;
        while (!maxHeap.empty()) {
            auto [count, c] = maxHeap.top();
            maxHeap.pop();
            res.append(count, c);
        }

        return res;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}