#include<bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int val) {
        long long value = val;
        if (st.empty()) {
            mini = value;
            st.push(value);
        } else {
            if (value >= mini) {
                st.push(value);
            } else {
                // Store encoded value as long long to avoid overflow
                st.push(2LL * value - mini);
                mini = value;
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long topVal = st.top();
        st.pop();

        if (topVal < mini) {
            // Decode previous mini
            mini = 2LL * mini - topVal;
        }
    }

    int top() {
        if (st.empty()) return -1;

        long long topVal = st.top();
        if (topVal >= mini) {
            return topVal;
        } else {
            return mini;
        }
    }

    int getMin() {
        if (st.empty()) return -1;
        return mini;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    MinStack minStack;

    return 0;
}
