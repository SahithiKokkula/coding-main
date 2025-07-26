#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    int energytill(int index,vector<int>&energy,int n,vector<int>&heights){
        if (index == 0) return 0;
        if (energy[index] != INT_MAX) return energy[index];
        int one_step = energytill(index - 1 , energy , n ,heights) + abs(heights[index] - heights[index-1]);
        int two_step = (index > 1 )?(energytill(index - 2 , energy , n ,heights) + abs(heights[index] - heights[index-2])) : INT_MAX;
        return energy[index] = min(one_step,two_step);
    }
public:
    int frogJump(vector<int>& heights) {
        int n = heights.size();
        vector<int>energy(n,INT_MAX);
        energy[0] = 0;
        return energytill(n-1,energy,n,heights);
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    vector<int>heights = {7, 5, 1, 2, 6};
    cout<<solution.frogJump(heights)<<endl;
    return 0;
}