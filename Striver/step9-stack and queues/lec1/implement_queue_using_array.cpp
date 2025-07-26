#include<bits/stdc++.h>
using namespace std;

class Queue{
    int * arr;
    int start, end, currSize, maxSize;
    public:
    Queue() {
        arr = new int[16];
        start = -1;
        end = -1;
        currSize = 0;
    }

    Queue(int maxSize) {
        ( * this).maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
  }
public:
    void push(int x){
        if(currSize == maxSize){
            cout<<"Queue is full";
        }
        if(end == -1){
            start = 0;
            end = 0;
        }
        else{
            end = (end + 1) % maxSize;
        }
        arr[end] = x;
        currSize++;
    }
    int pop(){
        if(start == -1){
            cout<<"Queue is empty";
            return -1;
        }
        int x = arr[start];
        if(currSize == 1){
            start = -1;
            end = -1;
        }
        else{
            start = (start + 1) % maxSize;
        }
        currSize--;
        return x;
    }

    int top(){
        if(start == -1){
            cout<<"Queue is empty";
            return 0;
        }
        return start;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}