#include <iostream>
using namespace std;

int main(){
    bool cond=false;
    int n;
    cin>>n;
    int weight[n];
    for (int i=0;i<n;i++){
        cin>>weight[i];
    }
    int k=0;
    int total_combinations[n*(n-1)/2];
    int freq[100];
    for(int i=0;i<100;i++){
        freq[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int t=weight[i]+weight[j];
            total_combinations[k++]=t;
            freq[t]+=1;
            if(weight[i]==weight[j] && cond==false){
                cond=true;
            }
        }
    }
    int max=0;
    for(int i=0;i<100;i++){
        if(freq[i]>max){
            max=freq[i];
        }
    }
    if(cond=true){
        cout<<max/2;
    }
    else{
        cond<<max;
    }
    

}


