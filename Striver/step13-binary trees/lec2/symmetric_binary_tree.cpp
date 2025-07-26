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

class Solution{
public:
    bool symmetricUtil (TreeNode * root1 , TreeNode * root2){
        if (root1 == NULL || root2 == NULL) {
            return (root1 == root2);
        }
        return (root1->val == root2->val) && symmetricUtil(root1->left , root2->right) && symmetricUtil(root1->right,root2->left);
    }
public:
    bool symmetric(TreeNode * root){
        if (!root ) return true;
        
        return symmetricUtil(root->left,root->right);

    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->right->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    Solution solution;
    bool result = solution.symmetric(root);
    cout<<result;
    return 0;
}