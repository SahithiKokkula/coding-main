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
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, 
        int inStart, int inEnd, int& preIndex, unordered_map<int, int>& inorderMap) {
        if (inStart > inEnd) return nullptr;
        
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        
        int inIndex = inorderMap[rootVal];
        
        root->left = buildTreeHelper(preorder, inorder, inStart, inIndex - 1, preIndex, inorderMap);
        root->right = buildTreeHelper(preorder, inorder, inIndex + 1, inEnd, preIndex, inorderMap);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inorderMap[inorder[i]] = i;
        }
        
        int preIndex = 0;
        return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1, preIndex, inorderMap);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}