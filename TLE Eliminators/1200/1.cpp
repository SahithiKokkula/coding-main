#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];
        for(int i = 0; i < n; i++) cin >> c[i];
        
        multiset<pair<int, int>> msetb, msetc;
        
        for(int i = 0; i < n; i++){
            msetb.insert({b[i], i});
            msetc.insert({c[i], i});
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            // Remove the current element from the multisets
            msetb.erase(msetb.find({b[i], i}));
            msetc.erase(msetc.find({c[i], i}));
            
            // Get the top two elements from msetb and msetc
            auto itb1 = msetb.rbegin();
            auto itc1 = msetc.rbegin();
            
            if (itb1->second == itc1->second) {
                // If the top elements are from the same index, consider the second top elements
                auto itb2 = next(itb1);
                auto itc2 = next(itc1);
                
                if (itb2 != msetb.rend() && itc2 != msetc.rend()) {
                    ans = max(ans, a[i] + itb1->first + itc2->first);
                    ans = max(ans, a[i] + itb2->first + itc1->first);
                }
            } else {
                // If the top elements are from different indices, just add them
                ans = max(ans, a[i] + itb1->first + itc1->first);
            }
            
            // Reinsert the elements back into the multisets
            msetb.insert({b[i], i});
            msetc.insert({c[i], i});
        }
        
        cout << ans << endl;
    }
    return 0;
}