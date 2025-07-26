#include<bits/stdc++.h>
using namespace std;
vector<int> frequencyCount(vector<int>& arr){
    int arrsize= arr.size();
    vector <int> hash(arrsize,0);
    for (int i=0;i<arrsize;i++){
        hash[arr[i]-1]++;
    }
    // hash.erase(hash.begin());W
    return hash;
}
int main(){
    int n;
    cin>>n;
    
    vector<int>arr(n);
    while (n--){
        cin>>arr[n];
    }
    vector<int>hash=frequencyCount(arr);
    for (int i=0;i<hash.size();i++){
        cout<<i+1<<" "<<hash[i]<<"\n";
    }
    return 0;
}