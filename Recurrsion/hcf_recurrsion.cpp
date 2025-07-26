#include<iostream>
using namespace std;
// Method-1
int hcf1(int x, int y, int ptr=-1){
    if(x>y){
        int tmp;
        tmp=x;
        x=y;
        y=tmp;
    }
    if(ptr==-1) ptr=x;
    if (ptr==0) return 1;
    if(x%ptr==0 && y%ptr==0) return ptr;
    hcf1(x,y,ptr-1);
}
// Method-2 (Euclids Algorithm) (Subtraction Method)
int hcf2(int x,int y){
    if (x==1||y==1) return 1;
    if (x==y) return x;
    if(x>y){
        int tmp;
        tmp=x;
        x=y;
        y=tmp;
    }
    int sub=y-x;
    hcf2(x,sub);
}
// Method-3 (Euclids Algorithm) (Division Method)
int hcf3(int x, int y){
    if (x==1||y==1) return 1;
    if (x==y) return x;
    if(x>y){
        int tmp;
        tmp=x;
        x=y;
        y=tmp;
    }
    int rem=y%x;
    hcf2(x,rem);
}
int main(){
    cout<<hcf1(72,54);
    cout<<endl;
    cout<<hcf2(72,54);
    cout<<endl;
    cout<<hcf3(72,54);
    return 0;
}