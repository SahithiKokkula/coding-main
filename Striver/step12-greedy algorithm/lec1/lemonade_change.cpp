#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool lemonadeChange(vector<int>& bills) {
        int bill_5 = 0, bill_10 = 0, bill_20 = 0;
        int change = 0;
        for(auto it : bills){
            if (it == 5){
                bill_5++;
                continue;
            }
            else if (it == 10) {
                bill_10++;
                if (bill_5 > 0){
                    bill_5--;
                    continue;
                }
                else{
                    return false;
                }
            }
            else{
                bill_20++;
                if (bill_10 > 0 && bill_5 > 0){
                    bill_10--;
                    bill_5--;
                    continue;
                }
                else if (bill_5 > 2){
                    bill_5 -= 3;
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int n;
    cin>>n;
    vector<int>bills(n);
    for(int i=0;i<n;i++){
        cin>>bills[i];
    }
    bool result = solution.lemonadeChange(bills);
    cout<<result?"true":"false";
    return 0;
}