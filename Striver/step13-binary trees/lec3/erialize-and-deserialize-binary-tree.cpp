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
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s = "";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode * currNode = q.front();
            q.pop();
            if(currNode == NULL) s.append("#,");
            else s.append(to_string(currNode->val) + ',');
            if(currNode != NULL){
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        return s;
    }
public:
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,','); // gives eash string partition partitioned by delimeter ',' each time i do getline function in str string.
        TreeNode * root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode * node = q.front();
            q.pop();
            getline(s,str,',');
            if(str == "#"){
                node->left = NULL;
            }
            else{
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
            getline(s,str,',');
            if(str == "#"){
                node->right = NULL;
            }
            else{
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
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