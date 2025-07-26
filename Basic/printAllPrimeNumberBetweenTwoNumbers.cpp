#include<iostream>
using namespace std;
int n_prime(int n){
    int i=2;
    int c=0;
    while(i<=n/2){
        // cout<<i;
        if ((n%i)==0){
            c=1;
            break;
        }  
        i++; 
    }
    if (c==0){
        cout<<n<<" ";
    }
}
int main(){
    int l_limit;
    int u_limit;
    cout<<"Enter two numbers";
    cin>>l_limit>>u_limit;
    cout<<"prime numbers are: ";
    for (int i=l_limit;i<=u_limit;i++){
        n_prime(i);
    }
}