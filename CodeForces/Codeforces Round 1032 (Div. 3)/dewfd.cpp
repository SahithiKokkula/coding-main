/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

int main() {


    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        unordered_map<int, int> freq;
        int max1 = INT_MIN;
        int max2 = INT_MIN;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin>>a[i][j];
                freq[a[i][j]]++;

                if (a[i][j] > max1) {
                    max2 = max1;
                    max1 = a[i][j];
                } else if (a[i][j] > max2 && a[i][j] < max1) {
                    max2 = a[i][j];
                }
            }
        }
        if(n==1 && m==1){
            cout<< a[0][0]-1 << '\n';
            continue;
        }

        int result;
        if (freq[max1]==1) {
            result = max(max2, max1 - 2); 
        } else {
            result = max1-1; 
        }

        cout << result << '\n';
    }

    return 0;
}
