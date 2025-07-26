#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val1) {
        val = val1;
        left = nullptr;
        right = nullptr;
    }

    TreeNode(int val1, TreeNode *left1, TreeNode *right1) {
        val = val1;
        left = left1;
        right = right1;
    }
};

class Solution {
public:
    // Function to count nodes
    // in a binary tree
    int countNodes(TreeNode* root) {
        // Base case: If the root
        // is NULL, there are no nodes
        if (root == NULL) {
            return 0;
        }
        
        // Find the left height and
        // right height of the tree
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);
        
        // Check if the last level
        // is completely filled
        if (lh == rh) {
            // If so, use the formula for
            // total nodes in a perfect
            // binary tree ie. 2^h - 1
            return (1 << lh) - 1; 
        }
        
        // If the last level is not completely
        // filled, recursively count nodes in
        // left and right subtrees
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    
    // Function to find the left height of a tree
    int findHeightLeft(TreeNode* node) {
        int height = 0;
        // Traverse left child until
        // reaching the leftmost leaf
        while (node) {
            height++;
            node = node->left;
        }
        return height;
    }
    
    // Function to find the right height of a tree
    int findHeightRight(TreeNode* node) {
        int height = 0;
        // Traverse right child until
        // reaching the rightmost leaf
        while (node) {
            height++;
            node = node->right;
        }
        return height;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}
