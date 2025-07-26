#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> search(string &pat, string &txt) {
        int i = 0, j = 0, idx =0;
        vector<int>ans;
        while(txt[idx] != '\0'){
            if(pat[i] == txt[j]){
                while(pat[i] != '\0'){
                    if(txt[j] == '\0'){
                        idx = j;
                        break;
                    }
                    if(pat[i] != txt[j]){
                        i = 0;
                        idx = j++;
                        break;
                    }
                    else{
                        if (pat[i + 1] =='\0'){
                            ans.push_back(idx + 1);
                        }
                    }
                    i++;
                    j++;
                }
            }
            else{
                idx++;
                i = 0;
                j = idx;
            }
        }
        return ans;
    }
};
class rabin_karp_algo {
private:
    pair<long long,long long>hash(string s, int n, long long RADIX_1, long long RADIX_2,long long MOD_1, long long MOD_2){
        long long factor_1 = 1;
        long long factor_2 = 1;
        long long hash_1 = 0;
        long long hash_2 = 0;
        for(int i = n-1; i >= 0; i--){
            hash_1 += ((s[i] - 'a') * factor_1) % MOD_1;
            factor_1 = (factor_1 * RADIX_1) % MOD_1;
            hash_2 += ((s[i] - 'a') * factor_2) % MOD_2;
            factor_2 = (factor_2 * RADIX_2) % MOD_2;
        }
        return {hash_1 % MOD_1, hash_2 % MOD_2};
    }
public:
    vector<int> rabin_karp(string &pat, string &txt) {
        int n = pat.size();
        int m = txt.size();
        vector<int>ans;
        if (n > m) return ans;
        long long RADIX_1 = 26;
        long long RADIX_2 = 27;
        long long MOD_1 = 1e9 + 7;
        long long MOD_2 = 1e9 + 33;
        long long MAX_1 = 1;
        long long MAX_2 = 1;
        for(int i = 0 ; i < n ; i++){
            MAX_1 = (MAX_1 * RADIX_1) % MOD_1;
            MAX_2 = (MAX_2 * RADIX_2) % MOD_2;
        }


        pair<long long,long long> hash_pat = hash(pat,n,RADIX_1,RADIX_2,MOD_1,MOD_2);
        pair<long long,long long>hash_txt = {0,0};
        for(int i = 0 ; i < m - n ; i++){
            if(i == 0){
                hash_txt =  hash(txt,n,RADIX_1,RADIX_2,MOD_1,MOD_2);
            }
            else{
                hash_txt.first = (hash_txt.first * RADIX_1) % MOD_1 - (MAX_1 * (txt[i-1] - 'a')) % MOD_1 + ((txt[i + n - 1] - 'a') + MOD_1) % MOD_1;
                if(hash_txt.first < 0) hash_txt.first += MOD_1;
                hash_txt.second = (hash_txt.second * RADIX_2) % MOD_2 - (MAX_2 * (txt[i-1] - 'a')) % MOD_2 + ((txt[i + n - 1] - 'a') + MOD_2) % MOD_2;
                if(hash_txt.second < 0) hash_txt.second += MOD_2;
            }
            if(hash_pat.first == hash_txt.first && hash_pat.second == hash_txt.second){
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    rabin_karp_algo rka;
    string text = "birthdayboybir", pattern = "birth";
    vector<int>ans = rka.rabin_karp(pattern,text);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}