#include<bits/stdc++.h>
using namespace std;
int count_digit(int n){
    int tmp =n;
    int digits=0;
    int c_digits=0;
    while (tmp>0)
    {
        int digit=tmp%10;
        if(digit!=0 && n%digit==0){
            c_digits+=1;
        }
        digits++;
        tmp/=10;
    }
    return c_digits;

}
int main(){
    int n;
    cin>>n;
    cout<<count_digit(n);
    return 0;
}