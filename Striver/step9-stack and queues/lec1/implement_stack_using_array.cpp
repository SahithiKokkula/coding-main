#include<bits/stdc++.h>
using namespace std;

class Stack{
    int size;
    int * arr;
    int top;
    Stack(){
        size = 1000;
        top = -1;
        arr = new int[size];
    }
    void push(int num){
        top++;
        arr[top] = num;
    }
    int pop(){
        int x = arr[top];
        top--;
        return x;
    }
    int Top(){
        return top;
    }
    int Size(){
        return top + 1;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}