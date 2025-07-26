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
        // OR

        // Node * temp = new Node(arr[i],nullptr,prev);
        // prev->next = temp;
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
    // temp = temp->back;
    // while (temp){
    //     cout<<temp->data<<" ";
    //     temp = temp->back;
    // }
    // cout<<endl;
    return;
}
Node * delete_head(Node * head){
    if (head==NULL || head->next == NULL) return head;
    Node * temp = head;
    head=head->next;
    head->back = nullptr;
    free(temp); // or delete temp;
    return head;
}
Node * delete_tail(Node * head){
    if (head == NULL || head->next == NULL) return NULL;
    Node * temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node * delete_k(Node * head,int k){
    if (head == NULL) return head;
    if (k==1) delete_head(head);
    Node * temp = head;
    int c=0;
    while(temp != NULL){
        c++;
        if (c==k) break;
        temp = temp->next;
    }
    Node * prev = temp->back;
    Node * front = temp->next;
    if (prev == NULL &&  front == NULL){
        return NULL;
    }
    else if (prev ==  NULL){
        return delete_head(head);
    }
    else if (front ==  NULL){
        return delete_tail(head);
    }
    prev->next=front;
    front->back=prev;
    delete temp;
    return head;
}


void delete_node(Node * temp){
    Node * prev = temp->back;
    Node * front = temp->next;
    if (front == NULL) {
        prev->next = nullptr;
        free(temp);
        return;
    }
    prev->next = front;
    front->back = prev;
    free(temp);
    return;
}

Node * insert_head(Node *head,int val){
    Node * newhead =  new Node(val,head,nullptr);
    head->back= newhead;
    return newhead;
}

Node * insert_before_tail(Node *head, int val){
    if (head == NULL) return new Node(val);
    if (head->next == NULL) return insert_head(head,val);
    Node * temp = head;
    while(temp->next){
        temp = temp->next;
    }
    Node * prev = temp->back;
    Node * newNode = new Node(val,temp,temp->back);
    temp->back=newNode;
    prev->next=newNode;
    return head;
}

int main(){
    vector<int>arr = {5, 10, 12, 15, 16, 23, 50, 56, 72};
    // create linked list
    Node * head = arr_to_linked_list(arr);

   
    // delete head 
    head = delete_head(head);

    // delete tail
    head = delete_tail(head);

    // delete kth element 
    head = delete_k(head,4);
    
    // delete element by value 
    delete_node(head->next);

    // insertion of head
    head = insert_head(head,100); 

    // insert at tail
    head = insert_before_tail(head,100);
    
    // print 
    print_dll(head);
    


    return 0;
}