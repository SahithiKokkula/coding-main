#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    void solve(){
        int n;
        cin>>n;
        vector<int>arr(n);
        int num;
        bool check = true;
        bool check2 = false;
        for(int i = 0 ; i < n ; i++){
            cin>>num;
            if(((num % 10) & 1) == 1){
                num = num + (num % 10);
            }
            if (num % 10 != 0) check = false;
            else check2 = true;
            arr[i] = num;
        }
        if(n == 1){
            cout<<"Yes"<<endl;
            return;
        }
        if(check){
            for(int i = 0 ; i < n ; i++){
                if(arr[i] != arr[i+1]){
                    cout<<"No"<<endl;
                    return;
                }
            }
            cout<<"Yes"<<endl;
            return;
        }
        if(check2){
            cout<<"NO"<<endl;
            return;
        }
        int digit = arr[0] % 10;
        for(int i = 1 ; i < n ;i++){
            while((arr[i] % 10) != digit){
                arr[i] = arr[i] + (arr[i] % 10);
            }
            if(((abs(arr[i] - arr[0])) % 20) != 0){
                cout<<"No"<<endl;
                return;
            }
        }
        cout<<"Yes"<<endl;
        return;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int t;
    cin>>t;
    while (t--){
        solution.solve();
    }
    
    return 0;
}