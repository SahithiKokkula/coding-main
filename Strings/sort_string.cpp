/*
Given a strings str, sort the given string.

Constraints: The string will contain only alphabetical characters from a-z.

Input 1: "codingwallah"

Output 1: "aacdghillnow"

Input 2: "star"

Output 2: "arst"
*/
#include<iostream>
#include<string>
using namespace std;
string sort(string &s){
    int freq_arr[26]={0};
    int n=0;
    for(int i:s){
        freq_arr[i-97]++;
        n++;
    }
    
    
    char sorted[n];
    int j=0;
    for(int i=0;i<26;i++){
        if(freq_arr[i]!=0){
            while(freq_arr[i]--){
                sorted[j++]=((char)(i+97));
            }
        }
    }
    for(char i:sorted){
        cout<<i;
    }
}
int main(){
    string str;
    cin>>str;
    sort(str);
}