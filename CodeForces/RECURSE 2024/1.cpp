#include<iostream>
using namespace std;
int main(){
    int test_cases;
    cin>>test_cases;
    int arr[test_cases];
    for(int i=0;i<test_cases;i++){
        int n,m,r,c;
        cin>>n>>m;
        cin>>r>>c;
        int turns=0;
        if(r+2<=n){
            if(c+1<=m) turns++;
            if(c-1>=1) turns++;
        }
        if(r-2>=1){
            if(c+1<=m) turns++;
            if(c-1>=1) turns++;
        }
        if(c+2<=m){
            if(r+1<=n) turns++;
            if(r-1>=1) turns++;
        }
        if(c-2>=1){
            if(r+1<=n) turns++;
            if(r-1>=1) turns++;
        }
    arr[i]=turns;
    }
    for(int i=0;i<test_cases;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}