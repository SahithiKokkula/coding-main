#include<iostream>
using namespace std;
double powerxn (double num,int pow){
    if (pow == 0) return 1;
    return num * powerxn(num,pow-1);
}
int main(){
    cout<<powerxn(2.1,3);
}