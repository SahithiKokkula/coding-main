#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cout<<"Enter Binary Number:";
    cin>>n;
    cout<<endl;

    int dec =0 ;
    int i=0;
    while(n!=0){
        dec=(n%10)*(pow(2,i));
        i++;
        n=n/10;
    }
    cout<<"Converted decimal Number:"<<dec;

}