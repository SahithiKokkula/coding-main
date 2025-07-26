#include<iostream>
#include<math.h>
using namespace std;
bool palindrome(int no,int *temp){
    if(no/10==0){
        int last_digit_tmp=(*temp)%10;
        (*temp)/=10;
        return ((no%10)==last_digit_tmp) ;
    }
    bool result= palindrome(no/10,temp) and (no%10==*temp%10);
    (*temp)/=10;
    return result;
}
int main(){
    int no = 12331;
    int temp=12331;
    int *t=&temp;
    cout<<palindrome(no,t);
    return 0;
}