// Time Complexity: O(n) && Space Complexity: O(1)


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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>inorder;
        TreeNode * cur = root;
        while(cur != NULL){
            if (cur->left == NULL){
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode * next = cur->left;
                while(next->right != NULL && next->right != cur){
                    next = next->right;
                }
                if(next->right == NULL){
                    next->right = cur;
                    cur = cur->left;
                }
                else{
                    next->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return inorder;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}