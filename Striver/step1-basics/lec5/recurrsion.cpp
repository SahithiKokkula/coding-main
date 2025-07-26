#include<bits/stdc++.h>
using namespace std;
void printn(int n,int i=1){
    if (i>n) return;
    cout<<i<<" ";
    printn(n,i+1);
}
void printgfg(int n,int i=1){
    if (i>n) return;
    cout<<"GFG ";
    printgfg(n,i+1);
}
void printNos(int N){
    if (N<=0) return;
    cout<<N<<" ";
    printNos(N-1);
}
int main(){
    int num;
    cin>>num;
    // printn(num);
    // printgfg(num);
    printNos(num);
    return 0;
}