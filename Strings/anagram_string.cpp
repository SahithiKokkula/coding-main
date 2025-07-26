/*Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Constraints : String s and t will only contain lowercase alphabetical characters.

Input 1: s = "anagram", t = "nagaram"

Output 1: yes

Input 2: s = "bank", t = "atm"

Output 2: no*/
#include<iostream>
#include<string>
using namespace std;
bool anagram(string a,string b){
    int freq_arr1[26]={0};
    for(int i:a){
        freq_arr1[i-97]++;
    }
    int freq_arr2[26]={0};
    for(int i:b){
        freq_arr2[i-97]++;
    }
    for(int i=0;i<26;i++){
        if(freq_arr1[i]!=freq_arr2[i]) return false;
    }
    return true;
}
int main(){
    string a,b;
    cin>>a>>b;
    if(anagram(a,b)) cout<<"YES";
    else cout<<"NO";
}