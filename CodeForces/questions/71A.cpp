#include<iostream>
#include<string.h>
int main(){
    int n;
    std::cin>>n;
    string a[n];
    for(int i=0;i<n;i++){
        string b;
        std::cin>>b;
        if (len(b) >10){
            b=b[0]+str(len(b))+b[len(b-1)]

        }
        a[i]=b;
    }
    for(int i=0;i<n;i++){
        std::cout<<a[i];
    }
    return 0;
}