#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<int> nse(vector<int> &arr) {
        int n = arr.size();
        vector<int> next(n, n); // default: no smaller => n
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                next[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return next;
    }

    vector<int> pse(vector<int> &arr) {
        int n = arr.size();
        vector<int> prev(n, -1); // default: no smaller => -1
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prev;
    }

public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        vector<int> nextSmaller = nse(arr);
        vector<int> prevSmaller = pse(arr);

        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long right = nextSmaller[i] - i;
            long long left = i - prevSmaller[i];
            total = (total + (left * right % mod) * arr[i]) % mod;
        }
        return (int)total;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}