#include<bits/stdc++.h>
using namespace std;
class ListNode{
    public:
    int val;
    ListNode * next;

    public:
    ListNode(int val1, ListNode * next1){
        val = val;
        next = next;
    }
    
    public:
    ListNode(int val1){
        val = val1;
        next = nullptr;
    }
};

ListNode* arr_to_linked_list(vector<int>arr){
    int n = arr.size();
    ListNode * head = new ListNode(arr[0]);
    ListNode * mover = head;
    for(int i=1;i<n;i++){
        ListNode * temp = new ListNode(arr[i]);
        mover->next=temp;
        mover = temp;
    }
    return head;
}

int helper(ListNode * head){
    if (head == NULL) return 1;
    int carry = helper(head->next);
    head->val += carry;
    if (head->val < 10) return 0;
    head->val = 0;
    return 1;
}
ListNode * add_one(ListNode * head){
    int carry = helper(head);
    if (carry == 1){
        ListNode * newnode = new ListNode(1);
        newnode->next = head;
        return newnode;
    }
    return head;
}

void print_ll(ListNode * head){
    ListNode * temp = head;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}

int main(){
    vector <int>arr={1,2,3,4,5,6};
    ListNode * head = arr_to_linked_list(arr);
    head = add_one(head);
    print_ll(head);
    return 0;
}