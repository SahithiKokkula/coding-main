#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int data1) {
        data = data1;
        left = nullptr;
        right = nullptr;
    }

    Node(int data1, Node *left1, Node *right1) {
        data = data1;
        left = left1;
        right = right1;
    }
};

class Solution{
    int findCeil(Node* root, int input) {
        int ceil = INT_MAX;
        while(root != NULL){
            if(root->data == input){
                return input;
            }
            else if(root->data > input){
                ceil = min(root->data , ceil);
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return ceil != INT_MAX ? ceil : -1;        
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}