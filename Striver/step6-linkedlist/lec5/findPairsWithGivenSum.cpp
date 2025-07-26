#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*back;

    public:
    Node(int data1,Node *  next1, Node * back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* arr_to_linked_list(vector<int>arr){
    int n = arr.size();
    Node * head = new Node(arr[0]);
    Node * prev = head;
    for(int i=1;i<n;i++){
        Node * temp = new Node(arr[i]);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }
    return head;
}

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
    vector<pair<int, int>> pairs;
    if (head == NULL || head->next == NULL) return pairs;
    Node * left = head;
    Node * right = head->next;
    while (left->data + right->data <= target){
        right = right->next;
    }
    while(left != right && left->back != right){
        int sum = left->data + right->data;
        if (sum == target){ 
            pairs.push_back({left->data,right->data});
            left = left->next;
        }
        else if (sum > target) right = right->back;
        else left = left->next;
    }
    return pairs;
}

int main(){
    vector<int>arr = {1,2,3,4};
    Node * head = arr_to_linked_list(arr);
    vector<pair<int,int>> pairs = findPairsWithGivenSum(head ,5);
    for (auto it : pairs){
        cout<<it.first<<" "<<it.second<<endl;
    }

    return 0;
}