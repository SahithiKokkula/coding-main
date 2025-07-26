#include<iostream>
using namespace std;

int domino_piling(int m, int n){
    if (n%2==0 || m%2==0){
        return (n*m)/2;
    }
    return (n*m-1)/2;
}
int main(){
    int n,m;
    cin>>m>>n;
    cout<<domino_piling(m,n);
}