#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    string addStrings(string a, string b) {
        string res;
        int carry = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            carry = sum / 10;
            res += (sum % 10) + '0';
        }
        reverse(res.begin(), res.end());
        return res;
    }

private: 
    bool check(string & s, int start,int l1,int l2){
        string s1 = s.substr(start,l1);
        string s2 = s.substr(start + l1,l2);
        if((s1.length() > 1 && s1[0] == '0') || (s2.length() > 1 && s2[0] == '0')) return false;
        string ans = addStrings(s1,s2);
        int l_ans = ans.length();
        if(start+l1+l2+l_ans > s.length()) return false;
        if(ans == s.substr(start+l1+l2,l_ans)){
            if(start+l1+l2+l_ans == s.length()) return true;
            return check(s,start+l1,l2,l_ans);
        }
        return false;
    }
public:
    bool isSumString(string &s) {
        int n = s.length();
        if(n<=2) return false;
        for(int l1 = 1 ; l1<n;l1++){
            for(int l2 = 1; l1+l2<n;l2++){
                if(check(s,0,l1,l2)) return true;
            }
        }
        return false;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    string s = "5016";
    cout<<solution.isSumString(s);
    return 0;
}