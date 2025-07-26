#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter integer:"<<endl;
    cin>>n;
    int sum=0;
    int i=1;
    do{
        if (i%3!=0){
            cout<<i<<endl;
        }
        sum=sum+i;
        i++;

    }while (i<=n);
    cout<<"Required sum: "<<sum;
}
