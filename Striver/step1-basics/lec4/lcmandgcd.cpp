#include<bits/stdc++.h>
using namespace std;
vector<int> lcmandgcd(int a,int b){
    vector <int> lcmgcd;
    int gcd=1;
    for(int i=min(a,b);i>0;i--){
        if(a%i==0&&b%i==0){
            gcd=i;
            break;
        }
    }
    int lcm=(a*b)/gcd;
    lcmgcd.emplace_back(lcm);
    lcmgcd.emplace_back(gcd);
    return lcmgcd;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<lcmandgcd(a,b)[0]<<" "<<lcmandgcd(a,b)[1];
    return 0;
}