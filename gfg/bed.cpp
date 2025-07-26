#include <bits/stdc++.h>
using namespace std;

void solve(int idx, int parts, int numFriends, string &word, vector<string> &path, set<string> &seenSplits, vector<vector<string>> &allSplits) {
    int n = word.length();
    
    if (parts == numFriends) {
        if (idx == n) {
            // Create a joined representation to detect uniqueness
            string key = "";
            for (auto &s : path) key += s + '|';  // '|' as delimiter
            if (seenSplits.find(key) == seenSplits.end()) {
                seenSplits.insert(key);
                allSplits.push_back(path);
            }
        }
        return;
    }

    for (int i = idx; i < n; ++i) {
        string sub = word.substr(idx, i - idx + 1);
        path.push_back(sub);
        solve(i + 1, parts + 1, numFriends, word, path, seenSplits, allSplits);
        path.pop_back();  // backtrack
    }
}

string findLexicographicallyLargest(string word, int numFriends) {
    vector<vector<string>> allSplits;
    set<string> seenSplits;
    vector<string> path;

    solve(0, 0, numFriends, word, path, seenSplits, allSplits);

    string ans = "";
    for (auto &split : allSplits) {
        for (string &s : split) {
            ans = max(ans, s);
        }
    }
    return ans;
}

int main() {
    string word = "dbca";
    int numFriends = 1;
    cout << findLexicographicallyLargest(word, numFriends) << endl;  // Output: "dbc"
    return 0;
}