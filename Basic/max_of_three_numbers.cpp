#include<iostream>
using namespace std;

int main(){
    int n1;
    int n2;
    int n3;
    int max;
    cout<<"enter number:"<<endl;
    cin>>n1>>n2>>n3;

    max =n1;
    if (n2>=max){
        max=n2;
    }
    if (n3>=max){
        max=n3;
    }
    cout<<"max number is: "<<max<<endl;
    return 0;
}
