#include<bits/stdc++.h>
using namespace std;
class MinStack{
private:
    stack<pair<int,int>>st;
    int minElement = INT_MAX;
public:
    void push(int val){
        minElement = min(minElement,val);
        st.push({val,minElement});
    }
    void pop(){
        if(st.empty()) return;
        st.pop();
        minElement = st.empty() ? INT_MAX : st.top().second;
    }
    int top(){
        return st.top().first;
    }
    int getMin(){
        return st.top().second;
    }

};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}