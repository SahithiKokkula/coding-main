#include<bits/stdc++.h>
using namespace std;
int sumofdivisors(int n){
    int sum=0;
    for (int j=1;j<=n;j++){
        set <int> divisors;
        for (int i=1;i<=pow(j,.5);i++){
            if (j%i==0){
                divisors.emplace(i);
                divisors.emplace(j/i);
            }
        }
        for (int it:divisors){
        cout<<it<<" ";
        sum+=it;
        }
        cout<<"\n";
    }
    return sum;
}
int main(){
    int n;
    cin>>n;
    cout<<sumofdivisors(n);
    return 0;
}