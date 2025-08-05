#include<bits/stdc++.h>
using namespace std;



class MyQueue {
private:
    stack<int> s1, s2;

public:
    MyQueue() {
        // No need to initialize stacks here as they are already declared.
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    MyQueue myQueue;

    return 0;
}