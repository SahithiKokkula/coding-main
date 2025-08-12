#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n= asteroids.size();
        vector<int> st;

        for(int i=0; i<n; i++){
            if(asteroids[i]>0){
                st.push_back(asteroids[i]);
            }
            else{
                while(!st.empty() && st.back()>0 && st.back()<abs(asteroids[i])){
                    st.pop_back();
                }
                if(!st.empty() && st.back()== -asteroids[i]){
                    st.pop_back();
                }
                else if(st.empty() || st.back()<0){
                    st.push_back(asteroids[i]);
                }
            }
        }
        return st;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;

    return 0;
}