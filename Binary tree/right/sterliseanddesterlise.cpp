#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:
    
    // Encodes a tree to a single string using preorder traversal.
    string serialize(TreeNode* root) {
        if (!root) return "X,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> nodes = split(data);
        return buildTree(nodes);
    }
    
    queue<string> split(const string& data) {
        queue<string> q;
        string token;
        for (char c : data) {
            if (c == ',') {
                q.push(token);
                token.clear();
            } else {
                token += c;
            }
        }
        return q;
    }
    
    TreeNode* buildTree(queue<string>& nodes) {
        if (nodes.empty()) return nullptr;
        
        string val = nodes.front();
        nodes.pop();
        
        if (val == "X") return nullptr;
        
        TreeNode* node = new TreeNode(stoi(val));
        node->left = buildTree(nodes);
        node->right = buildTree(nodes);
        
        return node;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Codec codec;


    TreeNode* root = new TreeNode(1,
                          new TreeNode(2),
                          new TreeNode(3, new TreeNode(4), new TreeNode(5)));

    string serialized = codec.serialize(root);
    cout << "Serialized: " << serialized << "\n";

    TreeNode* deserializedRoot = codec.deserialize(serialized);
    cout << "Deserialized and re-serialized: " << codec.serialize(deserializedRoot) << "\n";

    return 0; 
}
