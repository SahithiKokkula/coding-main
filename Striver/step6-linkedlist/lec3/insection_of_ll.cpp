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

ListNode * intersection_of_ll(ListNode * head1, ListNode * head2){
    if(head1 == NULL || head2 == NULL) return NULL;
    ListNode * d1 = head1;
    ListNode * d2 = head2;
    while(d1!=d2){
        d1 = d1 == NULL? head2:d1->next;
        d2 = d2 == NULL? head1:d2->next;
    }
    return d1;
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
    // ListNode * intersection = intersection_of_ll(head1,head2);
    // print_ll(intersection);
    return 0;
}