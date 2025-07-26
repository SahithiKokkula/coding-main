#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    for (int i=1;i<=n;i++){
        if(i%4==1){
            cout<<"*";
        }
        else if(i%2==0){
            cout<<"  *";
        }
        else if(i%4==3){
            cout<<"    *";
        }
        cout<<endl;
    }
    return 0;
}