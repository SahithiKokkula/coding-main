#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Next Greater Element (for max)
    vector<int> nge(vector<int> &arr) {
        int n = arr.size();
        vector<int> next(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                next[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return next;
    }

    // Previous Greater Element (for max)
    vector<int> pge(vector<int> &arr) {
        int n = arr.size();
        vector<int> prev(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            prev[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return prev;
    }

    // Next Smaller Element (for min)
    vector<int> nse(vector<int> &arr) {
        int n = arr.size();
        vector<int> next(n, n);
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

    // Previous Smaller Element (for min)
    vector<int> pse(vector<int> &arr) {
        int n = arr.size();
        vector<int> prev(n, -1);
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

    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextGreater = nge(arr);
        vector<int> prevGreater = pge(arr);

        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long right = nextGreater[i] - i;
            long long left = i - prevGreater[i];
            total += (left * right) * (long long)arr[i];
        }
        return total;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nextSmaller = nse(arr);
        vector<int> prevSmaller = pse(arr);

        long long total = 0;
        for (int i = 0; i < n; i++) {
            long long right = nextSmaller[i] - i;
            long long left = i - prevSmaller[i];
            total += (left * right) * (long long)arr[i];
        }
        return total;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}