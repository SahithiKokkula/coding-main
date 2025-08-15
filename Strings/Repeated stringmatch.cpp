#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        // Calculate the lengths of strings A and B
        int lengthA = A.size(), lengthB = B.size();
      
        // Calculate the initial repeat count to cover the length of string B
        int repeatCount = (lengthB + lengthA - 1) / lengthA;

        // Create an empty string t for concatenation
        string t = "";
      
        // Build the initial repeated string with repeatCount times of A
        for (int i = 0; i < repeatCount; ++i) {
            t += A;
        }

        // Check up to 2 more times of string A for the presence of B in t
        for (int i = 0; i < 2; ++i) {
          
            // If string B is found in t, return the current repeat count
            if (t.find(B) != string::npos) {
                return repeatCount;
            }

            // Increase repeat count and append string A to t
            ++repeatCount;
            t += A;
        }

        // If string B was not found, return -1
        return -1;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}