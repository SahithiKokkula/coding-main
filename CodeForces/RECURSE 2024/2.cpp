#include<iostream>
using namespace std;
int prime(int n){
    int fac;
    for(int i=2;i<=n;i++){
        if(n%i==0){
            fac=i;
            break;
        }
    }
    if(fac==n) return 1;
    return 0;
}
int two_factors(int n){
    int a,b;
    for(int i=2;i<=n;i++){
        if(n%i==0){
            a=i;
            b=n/i;
            break;
        }
    }
    if(prime(a)&&prime(b)){
        return 1;
    }
    else {
        return 0;
    }
}
int main(){
    int n;
    int h=0;
    cin>>n;
    for(int j=n;j>0;j--){
        if(two_factors(j*(j+1)/2)==1){
            h++;
        }
    }
    cout<<h;
    
    return 0;
}