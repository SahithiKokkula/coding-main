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

// preorder -> root left right
// inorder -> left root right
class Solution {
private:
    TreeNode* b_tree(vector<int>& preorder, vector<int>& inorder, int prestart, int preend, int instart, int inend,map<int,int>&inmap){
        if (instart > inend || prestart > preend) return NULL;
        TreeNode * root = new TreeNode(preorder[prestart]);

        int inroot = inmap[preorder[prestart]];
        int numleft = inroot - instart;

        root->left = b_tree(preorder,inorder,prestart + 1, prestart + numleft, instart, inroot - 1, inmap);
        root->right = b_tree(preorder,inorder,prestart + numleft + 1, preend, inroot + 1, inend, inmap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = 0;
        map<int,int>inmap;
        for(int it :inorder){
            inmap[it] = n;
            n++;
        }
        return b_tree(preorder, inorder, 0, n-1, 0, n-1, inmap);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}