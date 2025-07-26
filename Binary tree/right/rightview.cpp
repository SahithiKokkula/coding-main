#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void View(TreeNode* root, int level, vector<int>& ds) {
        if (!root) return;

        if (ds.size() == level) {
            ds.push_back(root->val);
        }

        View(root->right, level + 1, ds);
        View(root->left, level + 1, ds);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ds;
        View(root, 0, ds);
        return ds;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Create test tree: [1,2,3,null,5,null,4]
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    Solution sol;
    vector<int> result = sol.rightSideView(root);

    for (int val : result) {
        cout << val << " ";
    }

    cout << "\n";

    // Cleanup (not strictly needed in small test cases)
    delete root->left->right;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
