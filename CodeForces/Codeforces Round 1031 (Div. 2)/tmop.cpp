#include <bits/stdc++.h>
using namespace std;

void traverseEdge(int i, int j, int k, int n, int m) {
    int size = 2 * k + 1;
    int top = i - k;
    int bottom = i + k;
    int left = j - k;
    int right = j + k;

    vector<pair<int,int>> edge;

    // Top edge (left to right)
    for (int col = left; col <= right; col++) {
        int x = top;
        int y = col;
        if (x >= 0 && x < n && y >= 0 && y < m)
            edge.push_back({x, y});
    }

    // Right edge (top to bottom)
    for (int row = top + 1; row <= bottom - 1; row++) {
        int x = row;
        int y = right;
        if (x >= 0 && x < n && y >= 0 && y < m)
            edge.push_back({x, y});
    }

    // Bottom edge (right to left)
    for (int col = right; col >= left; col--) {
        int x = bottom;
        int y = col;
        if (x >= 0 && x < n && y >= 0 && y < m)
            edge.push_back({x, y});
    }

    // Left edge (bottom to top)
    for (int row = bottom - 1; row >= top + 1; row--) {
        int x = row;
        int y = left;
        if (x >= 0 && x < n && y >= 0 && y < m)
            edge.push_back({x, y});
    }

    // Print traversed edge
    if (!edge.empty()) {
        cout << "Center: (" << i << "," << j << ") -> ";
        for (auto it : edge)
            cout << "(" << it.first << "," << it.second << ") ";
        cout << endl;
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            traverseEdge(i, j, k, n, m);
        }
    }

    return 0;
}

