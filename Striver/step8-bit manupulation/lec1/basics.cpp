#include<bits/stdc++.h>
using namespace std;
string decimal_to_binary(int num){
    string binaryno = "";
    while (num!=1){
        if (num % 2 == 0) binaryno += "0";
        else binaryno += "0";
        num = num/2;
    }

    reverse(binaryno.begin(),binaryno.end());
    return binaryno;
}
int main(){
    cout<<decimal_to_binary(13);
}