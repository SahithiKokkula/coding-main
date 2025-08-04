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
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, 
                              int inStart, int inEnd, int& postIndex, unordered_map<int, int>& inorderMap) {
        if (inStart > inEnd) return nullptr;
        
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);
        
        int inIndex = inorderMap[rootVal];
        
        root->right = buildTreeHelper(inorder, postorder, inIndex + 1, inEnd, postIndex, inorderMap);
        root->left = buildTreeHelper(inorder, postorder, inStart, inIndex - 1, postIndex, inorderMap);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        
        int postIndex = postorder.size() - 1;
        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, postIndex, inorderMap);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}