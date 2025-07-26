#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n][6];
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int t1=arr[i][0]/arr[i][1]+arr[i][2];
        int t2=arr[i][3]/arr[i][4]+arr[i][5];
        if(t1<t2){
            cout<<"PAUL"<<endl<<t1<<endl;
        }
        else if(t1>t2){
            cout<<"NINA"<<endl<<t2<<endl;
        }
        else if(t1==t2){
            cout<<"BOTH"<<endl<<t2<<endl;
        }
    }
    
    
}
