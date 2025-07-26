#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,l,r,n,a;
    cin>>t;
    while(t--){
        cin>>n>>l>>r;
        vector<int>nums;
        for(int i=0;i<n;i++){
            cin>>a;
            nums.emplace_back(a);
        }
        long long ans1 = 0, ans2 = 0;
        multiset<int>ms;
        for (int i=l-1;i<r;i++){
            ms.emplace(nums[i]);
        }
        sort(nums.begin(),nums.begin()+l-1);
        sort(nums.begin()+r,nums.end());
        int i = 0;
        int j = r;
        for (int k = l-1;k<r;k++){ 
            int top = *ms.rbegin();
            if(i < (l - 1) && top > nums[i]){
                ans1 += nums[i++];
            }
            else{
                ans1 += top;
            }
            if (j < n && top > nums[j] ){
                ans2 += nums[j++];
            }
            else{
                ans2 += top;
            }
            ms.erase(ms.find(top));
        }
        cout<<min(ans1,ans2)<<endl;
    }
    return 0;
}
