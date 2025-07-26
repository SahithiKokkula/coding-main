#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n;
    cin>>t;
    
    while (t--){
        cin>>n;
        int ini = '0',count = 0;
        string str;
        cin>>str;
        for(int i = 0; i<n ;i++){
            if (str[i] != ini){
                count ++ ;
                ini = str[i];
            }
        }
        cout<<count<<endl;
    }
}