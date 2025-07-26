#include <bits/stdc++.h>
using namespace std;
void insert_at_bottom(stack<int>& st, int value) {
    if (st.empty()) {
        st.emplace(value); 
        return;
    }
    int top_element = st.top();
    st.pop();
    insert_at_bottom(st, value);  
    st.emplace(top_element);     
}

void reverse_stack(stack<int>& st) {
    if (st.empty()) return;  
    int top_element = st.top();
    st.pop();
    reverse_stack(st);       
    insert_at_bottom(st, top_element);  
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

    reverse_stack(st);  
    while (!st.empty()) {
        cout << st.top() << " ";  
        st.pop();                 
    }
    return 0;
}
