#include<iostream>
using namespace std;
int main(){
    int a[]={5,4,1,2,3};
    int size=sizeof(a)/sizeof(a[0]);
    for (int i=0;i<size;i++){
        if (i==0){
            a[i]==a[i];
        }
        else{
            a[i]=a[i]+a[i-1];
        }
    }
    for (int ele:a){
        cout<<ele<<" ";
    }

    return 0;
}