#include<iostream>
int power(int p,int q){
    if(q==0) return 1;
    return p*power(p,q-1);
}
int main(){
    std::cout<<power(2,0);
    return 0;
}