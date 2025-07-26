#include<bits/stdc++.h>
using namespace std;
set <int> print_divisors(int n){
    set <int> divisors;
    for (int i=1;i<pow(n,.5);i++){
        if (n%i==0){
            divisors.emplace(i);
            divisors.emplace(n/i);
        }
    }
    return divisors;
}
int main(){
    int n;
    cin>>n;
    set <int> finaldivisors=print_divisors(n);
    for (int it:finaldivisors){
        cout<<it<<" ";
    }
    return 0;
}