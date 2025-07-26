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
//post order = left right root
private:
    TreeNode * b_tree(vector<int>&inorder, vector<int>&postorder, int poststart,int postend, int instart,int inend,unordered_map<int,int>&inmap){
        if(poststart > postend || instart>inend) return NULL;

        TreeNode * root = new TreeNode(postorder[postend]);
        int inroot = inmap[postorder[postend]];
        int num_right = inend - inroot;
        root->left = b_tree(inorder,postorder,poststart, postend - num_right - 1 ,instart , inroot - 1,inmap);
        root->right = b_tree(inorder,postorder, postend - num_right, postend - 1  ,inroot + 1 , inend,inmap);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = 0;
        unordered_map<int,int>inmap;
        for(int it :inorder){
            inmap[it] = n;
            n++;
        }
        return b_tree(inorder,postorder,0,n-1,0,n-1,inmap);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}