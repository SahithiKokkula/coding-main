/*Given two strings s and t, determine if they are isomorphic.

Input : s = "egg", t = "add"
Output : yes
*/
#include<iostream>
#include<string>
using namespace std;
bool isomorphic(string a,string b){
    int n1=0,n2=0;
    for(char i:a){
        n1++;
    }
    for(char i:b){
        n2++;
    }
    if(n1!=n2) return false;
    int mapping[26]={0};
    for(int i=0;i<n1;i++){
        int a_int=a[i]-96;
        int b_int=b[i]-96;
        if(mapping[a_int]==0){
            mapping[a_int]=b_int;
        }
        else if(mapping[a_int]!=b_int){
            return false;
        }
    }
    return true;
}
int main(){
    string a,b;
    cin>>a>>b;
    if(isomorphic(a,b)) cout<<"YES";
    else cout<<"NO";
    return 0;
}