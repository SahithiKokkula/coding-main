#include<bits/stdc++.h>
using namespace std;
int check_drink(string drink,int n, int m,bool *check,int l ,int I ,int t,int target){
    if(m > 2*n) return -1;
    if (l == I  && I == t){
        *check = 1;
        return 1;
    }
    if (l <= target){
        for(int i = 0 ;i<n-1;i++){
            if (drink[i] != drink[i+1] && drink[i] != 'L' && drink[i+1] != 'L'){
                check_drink(drink.substr(0,i+1)+ 'L' +drink.substr(i+1),n,m+1,check,l+1,i,t,target);
            }
        }
    }
    if (I <= target){
        for(int i = 0 ;i<n-1;i++){
            if (drink[i] != drink[i+1] && drink[i] != 'I' && drink[i+1] != 'I'){
                check_drink(drink.substr(0,i+1)+ 'I' +drink.substr(i+1),n,m+1,check,l,i+1,t,target);
            }
        }
    }
    if (t <= target){
        for(int i = 0 ;i<n-1;i++){
            if (drink[i] != drink[i+1] && drink[i] != 'T' && drink[i+1] != 'T'){
                check_drink(drink.substr(0,i+1)+ 'T' + drink.substr(i+1),n,m+1,check,l,i,t+1,target);
            }
        }
    }
    return -1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string drink;
        cin>>drink;
        bool check  = 0;
        int lcount = 0, icount = 0, tcount = 0;
        for(int i = 0; i<n; i++){
            if (drink[i] == 'L') lcount++;
            if (drink[i] == 'T') tcount++;
            if (drink[i] == 'I') icount++;
        }
        if ((lcount == 0 && icount == 0) || (lcount == 0 && tcount == 0) || (tcount == 0 && icount == 0)){
            cout<<-1<<endl;
        }
        else{
            cout<<check_drink(drink,n,0,&check,lcount,icount,tcount,max(lcount,max(icount,tcount)))<<endl;
        }
    }
}