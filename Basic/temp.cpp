#include<iostream>
using namespace std;
void pattern(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void pattern1(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*n-1;j++){
            if(i+j>=n+1 && j-i <= n-1){
                cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
void pattern2(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        for(int k=1;k<=2*(n-i);k++){
            cout<<" ";
        }
        for(int l=i;l>=1;l--){
            cout<<l;
        }
        cout<<endl;
    }
}
int main(){
    int n;
    cin>>n;
    // pattern(n);
    // pattern1(n);
    pattern2(n);
}