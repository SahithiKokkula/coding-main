#include <bits/stdc++.h>
using namespace std;
void insert_sorted(stack<int>&st,int value){
    if(st.empty() || st.top()<=value){
        st.emplace(value);
        return;
    }
    int top_element = st.top();
    st.pop();
    insert_sorted(st,value);
    st.emplace(top_element);
}
void sort_stack(stack<int>&st){
    if (st.empty()) return;
    int top_element = st.top();
    st.pop();
    sort_stack(st);
    insert_sorted(st,top_element);
}

int main() {
    stack<int> st;
    int n;
    cin >> n; 
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num; 
        st.emplace(num);
    }

    sort_stack(st);  

    while (!st.empty()) {
        cout << st.top() << " ";  
        st.pop();                 
    }
    return 0;
}
