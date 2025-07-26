#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int sol1(vector<string>&classroom,int energy,int i,int j,int n,int m,int cnt){
        if(cnt == 0) return 0;
        
    }
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = 0;
        int c = 0;
        int cnt = 0;
        pair<int,int>coordinates;
        for(int i = 0 ; i < n ; i++){
            for(auto it:classroom[i]){
                if(i == 0) c++;
                if(it == 'L') cnt++;
                if (it == 'S') {
                    coordinates.first = i;
                    coordinates.second = m;
                }
                m++;
            }
            m = 0;
        }
        m = c;
        return sol1(classroom,energy,coordinates.first,coordinates.second,n,m,cnt);
       
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<string>classroom = {"L.", "SL"};
    int energy = 2;
    cout<<solution.minMoves(classroom,energy);
    return 0;
}
