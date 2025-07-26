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

class Solution{
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);

        TreeNode * curr = root;
        while (curr != NULL){
            if (curr->val < val){
                if (curr->right) curr = curr->right;
                else{
                    curr->right = new TreeNode(val);
                    break;
                }
            }
            else{
                if(curr->left) curr = curr->left;
                else{
                    curr->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}