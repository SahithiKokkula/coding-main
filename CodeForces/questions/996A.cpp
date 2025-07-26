#include<iostream>
int main(){
    int bills[]={1,5,10,20,100};
    int amount;
    std::cin>>amount;
    int n=0;
    for (int i=4;i>=0;i--){
        while(amount>=bills[i]){
            amount-=bills[i];
            n++;
        }
    }
    std::cout<<n;
    return 0;
}