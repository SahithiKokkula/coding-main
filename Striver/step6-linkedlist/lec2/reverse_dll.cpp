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

void print_dll(Node * head){
    Node * temp = head;
    while (temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    return;
}

Node * reverse_dll(Node * head){
    // we can revrese the links to reverse a doubly linked list 
    // also we can use a stack to first store all the elements of a linked list then reiterate over the linked list and update the value of each node 
    if (head == NULL || head->next ==  NULL) return head;
    Node * prev = NULL;
    Node * curr = head;
    while (curr){
        prev = curr->back;
        curr->back = curr->next;
        curr->next = prev;
        curr=curr->back;
    }
    return prev->back;

}
int main(){
    vector<int>arr = {5, 10, 12, 15, 16, 23, 50, 56, 72};
    // create linked list
    Node * head = arr_to_linked_list(arr);
    
    // reverse a dll
    head = reverse_dll(head);

    // print 
    print_dll(head);
    


    return 0;
}