#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;

    public:
    Node(int data1,Node *  next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
Node* arr_to_linked_list(vector<int>arr){
    int n = arr.size();
    Node * head = new Node(arr[0]);
    Node * mover = head;
    for(int i=1;i<n;i++){
        Node * temp = new Node(arr[i]);
        mover->next=temp;
        mover = temp;
    }
    return head;
}
Node * delete_head(Node * head){
    if (head==NULL) return head;
    Node * temp = head;
    head=head->next;
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
    Node * prev = NULL;
    int c=0;
    while(temp != NULL){
        c++;
        if (c==k){
            prev -> next = prev -> next -> next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
Node * delete_el(Node * head,int el){
    if (head == NULL) return head;
    if (head->data==el) delete_head(head);
    Node * temp = head;
    Node * prev = NULL;
    int c=0;
    while(temp != NULL){
        if (temp->data == el){
            prev -> next = prev -> next -> next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
        
    }
    return head;
}

Node * insert_head(Node *head,int val){
    return new Node(val,head);   
}

Node * insert_at_tail(Node *head, int val){
    if (head == NULL) return new Node(val);
    Node * temp = head;
    while(temp->next){
        temp = temp->next;
    }
    Node * newNode = new Node(val);
    temp -> next = newNode;
    return head;
}

Node * insert_at_k(Node* head , int val,int k){
    if (head == NULL) {
        if (k==1) return new Node(val);
        return NULL;
    }
    if (k==1) return insert_head(head, val);
    Node * temp = head;
    int c = 0;
    while (temp){
        c++;
        if (c==k-1){
            Node * newNode = new Node(val,temp->next);
            temp->next= newNode;   
            return head;
        }
        temp = temp->next;
    }
    return NULL;
}

Node * insert_before_element(Node* head , int val,int el){
    if (head == NULL) {
        return NULL;
    }
    if (head->data == el) return insert_head(head, val);
    Node * temp = head;
    while (temp){
        if (temp->next->data==el){
            Node * newNode = new Node(val,temp->next);
            temp->next= newNode;   
            return head;
        }
        temp = temp->next;
    }
    return NULL;
}
int main(){
    int n;
    cin>>n;
    int num;
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>num;
        arr.emplace_back(num);
    }
    // create linked list
    Node * head = arr_to_linked_list(arr);

   
    // delete head of link list
    head = delete_head(head);

    // delete tail
    head = delete_tail(head);

    // delete kth element 
    head = delete_k(head,2);
    
    // delete element by value 
    head = delete_el(head,2);

    // insertion of head
    head = insert_head(head,5); // or head = new Node(100,head);

    // insert at tail
    head = insert_at_tail(head,5);

    // insert at k
    head = insert_at_k(head,5,2);

    // insert element by value 
    head = insert_before_element(head,5,2);
    
    // traversal in inked list
    Node * temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    


    return 0;
}