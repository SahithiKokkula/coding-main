#include<bits/stdc++.h>
using namespace std;
// defining the TreeNode
class TreeNode{
    public:
    int val;
    TreeNode * left;
    TreeNode * right;

    public:
    TreeNode(int val1){
        val = val1;
        left = nullptr;
        right = nullptr;
    }

    public:
    TreeNode(int val1, TreeNode * left1, TreeNode * right1){
        val = val1;
        left = left1;
        right = right1;
    }
};
class Solution {
private:

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q) return root;
        TreeNode * left = lowestCommonAncestor(root->left,p,q);
        TreeNode * right = lowestCommonAncestor(root->right,p,q);
        if(right == NULL) return left;
        else if(left == NULL) return right;
        return root;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}