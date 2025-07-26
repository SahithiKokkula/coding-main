#include<bits/stdc++.h>
using namespace std;
int parseNumber(string s,int index,int sign,long result){
    if(index>=s.size()||!isdigit(s[index])) return result*sign;
    result = result * 10 + (s[index] - '0');
    if (result * sign >= INT_MAX) return INT_MAX;
    if (result * sign <= INT_MIN) return INT_MIN;
    return parseNumber(s, index + 1, sign, result);
}
int myAtoi(string s){
    int index = 0;
    while (index < s.size() && s[index] == ' ') {
        index++;
    }
    int sign = 1;
    if (index < s.size() && (s[index] == '+' || s[index] == '-')) {
        if (s[index] == '-') sign = -1;
        index++;
    }
    return parseNumber(s, index, sign, 0);
}
int main(){
    return 0;
}