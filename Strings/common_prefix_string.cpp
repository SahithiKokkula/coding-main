#include<iostream>
#include<string>
#include<vector>
using namespace std;
string common_prefix(vector<string>arr){
    
}
int main(){
    int n;
    cin>>n;
    vector<string>arr;
    for(int i=0;i<n;i++){
        string ele;
        cin>>ele;
        arr.push_back(ele);
    }
cout<<common_prefix(arr);
    return 0;
}