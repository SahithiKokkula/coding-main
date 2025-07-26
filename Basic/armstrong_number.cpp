/*An armstrong number is a number if the sum of every digit in that number
raised to the power of total digits in that number is equal to the number.*/

#include<iostream>
#include<math.h>
using namespace std;
// int f(int num,int tmp=0,int sum=0){
//     if(tmp==0 ) tmp=num;
//     if(num==0) return 0;
//     sum=pow((num%10),3)+f(num/10,tmp);
//     if (num!=tmp) return sum;
//     if(sum==num) return 1;
//     return 0;
// }

int f1(int num,int *n){

    if(num==0) return 0;
    *n+=1;
    int sum=f1(num/10,n)+pow((num%10),*n);
    return sum;
}
int main(){
    int n=0;
    int *digits=&n;
    cout<<f1(251,digits);
    return 0;
}