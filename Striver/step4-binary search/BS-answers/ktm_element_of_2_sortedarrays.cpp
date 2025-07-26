#include<bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     int kthElement(vector<int>& a, vector<int>& b, int k) {
//         int n1 = a.size();
//         int n2 = b.size();
//         if(n1>n2) return kthElement(b,a,k);
//         int low = max(0, k - n2), high = min(k, n1);
//         while(low <= high){
//             int mid1 = (low + high)/2;
//             int mid2 = k  - mid1;
//             int  l1 = (mid1 - 1 >=0)?a[mid1 - 1]:INT_MIN;
//             int  l2 = (mid2 - 1 >=0)?b[mid2 - 1]:INT_MIN;
//             int  r1 = (mid1 - 1 + 1 <= n1)?a[mid1 - 1 + 1]:INT_MAX;
//             int  r2 = (mid2 - 1 + 1 <= n2)?b[mid2 - 1 + 1]:INT_MAX;
//             if(l1 <= r2 && l2 <= r1) return max(l1,l2);
//             else if(r2 < l1)  high = mid1 - 1;
//             else low = mid1 + 1;
//         }
//         return -1;
//     }
// };



class Solution {
public:
    int kthElement(vector<int>& a, vector<int>& b, int k) {
        int n1 = a.size();
        int n2 = b.size();
        if (n1 > n2) return kthElement(b, a, k);  // always binary search on smaller array

        int low = max(0, k - n2), high = min(k, n1);  // we can take 0 to k elements from a

        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = k - cut1;

            int l1 = (cut1 > 0) ? a[cut1 - 1] : INT_MIN;
            int l2 = (cut2 > 0) ? b[cut2 - 1] : INT_MIN;
            int r1 = (cut1 < n1) ? a[cut1] : INT_MAX;
            int r2 = (cut2 < n2) ? b[cut2] : INT_MAX;

            if (l1 <= r2 && l2 <= r1)
                return max(l1, l2);
            else if (l1 > r2)
                high = cut1 - 1;
            else
                low = cut1 + 1;
        }
        return -1; // this shouldn't be reached in valid inputs
    }
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int> a = {2, 3, 6, 7, 9}, b = {1,4,8,10};
    int k = 5;
    cout<<solution.kthElement(a,b,k);
    return 0;
}