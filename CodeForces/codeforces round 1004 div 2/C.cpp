#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int check = -1;
        int k;
        for (int i=0;i<10;i++){
            k = i;
            int temp = n;
            temp = temp - i;
            int curr;
            while(temp>0){
                curr = temp % 10;
                temp = temp/10;
                if (curr + i == 7){
                    check = 1;
                    break;
                }
            }
            if (check == 1) break;
        }
        if (check == 1){
            cout<<k<<endl;
        }
    }
}