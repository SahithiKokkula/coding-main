#include<bits/stdc++.h>
using namespace std;
void generate_combination(int index, vector <string> & ans, string curr, vector <string> & phoneMap, string &digits){
    if (index == digits.length()) {
        ans.push_back(curr);
        return;
    }
    string letters = phoneMap[digits[index] - '0'];
    for (char letter : letters) {
        curr.push_back(letter);        
        generate_combination(index + 1, ans, curr, phoneMap, digits); 
        curr.pop_back();                
    }
}
vector<string> lettercombination(string digits){
    if (digits.empty()) return {}; 
    vector<string> phoneMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    generate_combination(0,  ans, "", phoneMap, digits);
    return ans;
}
int main(){
    string digits;
    cin>>digits;
    vector<string>ans = lettercombination(digits);
    cout<<"ans array\n\n\n\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}