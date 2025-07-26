// Generate all binary strings without consecutive 1’s
#include<bits/stdc++.h>
using namespace std;
void generate_strings(int index,vector<string>&ans,string curr,int k,int last_ele){
    if(index>=k) {
        ans.emplace_back(curr);
        return;
    }
    if (last_ele == 0){
        generate_strings(index+1,ans,curr+"0",k,0);
        generate_strings(index+1,ans,curr+"1",k,1);
    }
    else{
        generate_strings(index+1,ans,curr+"0",k,0);
    }
}
vector<string> binary_strings(int k){
    vector<string>ans;
    generate_strings(0,ans,"",k,0);
    return ans;
}
int main(){
    int k;
    cin>>k;
    vector<string>ans = binary_strings(k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}