#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    bool check(TreeNode* left, TreeNode* right) {
        if (left == NULL || right == NULL) {
            return left == right;
        }

        if (left->val != right->val) {
            return false;
        }

        return check(left->left, right->right) &&
               check(left->right, right->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return root == NULL || check(root->left, root->right);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution solution;

    // Create a symmetric binary tree
    //       1
    //     /   \
    //    2     2
    //   / \   / \
    //  3   4 4   3

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    bool result = solution.isSymmetric(root);
    cout << (result ? "Tree is symmetric\n" : "Tree is not symmetric\n");
    return 0;
}
