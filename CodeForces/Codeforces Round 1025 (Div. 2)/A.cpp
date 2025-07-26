#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        bool check = false;
        int cnt = 0;
        int prev;
        cin>>prev;
        if(prev == 1) cnt++;
        int num;

        for(int i = 1 ; i < n ; i++){
            cin>>num;
            if (prev == 0 && num == 0) check = true;
            if(num == 1) cnt++;
            prev = num;
        }
        if (cnt == n) check = true;
        cout<<((check)?"YES":"NO")<<endl;
    }
    return 0;
}