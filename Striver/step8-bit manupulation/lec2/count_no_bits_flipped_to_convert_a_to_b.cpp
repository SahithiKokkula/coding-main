#include<bits/stdc++.h>
using namespace std;
class Solution{
public: 
    int minBitFlips(int start, int goal) {
        int count = 0;
        for (int i=0;i<32;i++){
            if(((start >>i)&1) != ((goal>>i)&1)){
                count ++;
            }
        }      
        return count;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int start,end;
    cin>>start>>end;
    cout<<solution.minBitFlips(start,end);
}