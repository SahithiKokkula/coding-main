#include<bits/stdc++.h>
using namespace std;
vector<long long> facnumresult;
vector<long long>factorialNumbers(long long n,long long i=1,long long fac=1){
    if (fac>n) return facnumresult;
    facnumresult.emplace_back(fac);
    factorialNumbers(n,i+1,fac*i);
}
int main(){
    int n;
    cin>>n;
    facnumresult=factorialNumbers(n);
    for(auto it:facnumresult){
        cout<<it<<" ";
    }
    return 0;
}