#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cout<<"Enter decimal number: "<<endl;
    cin>>n;
    int rem=0;
    string bin_rev;
    do{
        rem=n%2;
        bin_rev+= to_string(rem);
        n=n/2;
    }while(n!=0);

    
    int bin=0;
    int bin_rem;
    bin_rem=stoi(bin_rev);
    do{
        rem=bin_rem%10;
        bin=bin*10+rem;
        bin_rem=bin_rem/10;
    }while(bin_rem !=0);
    
    cout<<" number"<<bin;
}
