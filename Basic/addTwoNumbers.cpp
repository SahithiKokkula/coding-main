#include <iostream>
using namespace std;
int main(){
    int number_1;
    int number_2;
    int a;
    cout<<"Enter first number...";
    cin>>number_1;
    cout<<"Enter second number...";
    cin>>number_2;
    cout<<"number 1: "<<number_1<<endl<<"number 2: "<<number_2<<endl;
    a= number_1;
    number_1=number_2;
    number_2=a;
    cout<<"swapped number 1: "<<number_1<<endl<<"swapped number 2: "<<number_2<<endl;
    cout<<"sum of given numbers is: "<<number_1+number_2;
    return 0;
}