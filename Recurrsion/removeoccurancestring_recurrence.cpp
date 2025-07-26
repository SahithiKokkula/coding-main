#include<iostream>
using namespace std;
string f(string &s, int n, int idx){
    if (idx==n) return "";
    string curr="";
    curr+=s[idx];
    return ((s[idx]=='a') ? "": curr)+f(s,n,idx+1);

}
int main(){
    string s="abcax";
    int len = 5;
    cout<<f(s,len,0);
    return 0;
}