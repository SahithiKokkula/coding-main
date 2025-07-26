#include<bits/stdc++.h>
using namespace std;
void parentheses_sequence(int indexleft, int indexright,vector<string>&ans,string curr,int k){
    if(indexleft>=k && indexright>=k){
        ans.emplace_back(curr);
        return;
    }
    if (indexleft < k) {
        parentheses_sequence(indexleft + 1, indexright, ans,curr + "(", k);
    }

    if (indexright < indexleft) {
        parentheses_sequence(indexleft , indexright+1, ans,curr + ")", k);
    }
    
}
vector<string> generate_parentheses(int k){
    vector<string>ans;
    parentheses_sequence(0,0,ans,"",k);
    return ans;
}
int main(){
    int k;
    cin>>k;
    vector<string>ans = generate_parentheses(k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" \n";
    }
    return 0;
}