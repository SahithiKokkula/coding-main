#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    int sol1(vector<vector<int>>&ponts , vector<vector<int>>&dp,int d ,int act){
        if (d==0) return 0;
        if(dp[d-1][act] != -1) return dp[d-1][act];
        int maxi = -1;
        for(int i = 0 ; i < 3;i++){
            if ( i != act){
                maxi = max(maxi , sol1(ponts,dp,d-1,i) + ponts[d-1][i]);
            }
        }
        dp[d-1][act] = maxi;
        return maxi;
    }

public:
    int ninjaTraining_memo(int n, vector<vector<int>> &points){
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return sol1(points,dp,n,3);
    }
public:
    int ninjaTraining_tabu(int n, vector<vector<int>>& points) {
        vector<vector<int>> dp(n, vector<int>(4, 0));

        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][0], points[0][1]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

        for (int day = 1; day < n; day++) {
            for (int last = 0; last < 4; last++) {
            dp[day][last] = 0;
                for (int task = 0; task <= 2; task++) {
                    if (task != last) {
                    int activity = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], activity);
                    }
                }
            }
        }
        return dp[n - 1][3];
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int n = 30;
    vector<vector<int>>points = {
        {83 ,66 ,76},
{40 ,15, 72},
{14 ,61, 88},
{63 ,35, 21},
{58 ,24, 61},
{91 ,10, 33},
{14, 3, 10},
{54 ,84, 39},
{53 ,32, 54},
{66 ,85, 70},
{77, 2, 22},
{56 ,56, 80},
{59 ,17, 99},
{5 ,43, 38},
{65, 67 ,7},
{72 ,46, 81},
{45 ,78, 74},
{8 ,41, 56},
{50 ,25, 55},
{8 ,47, 57},
{93 ,36, 36},
{98 ,51, 99},
{16 ,90, 14},
{64 ,60, 14},
{94 ,66, 59},
{45 ,78, 19},
{18 ,90, 15},
{95 ,90, 79},
{64, 26, 5},
{13 ,80, 67}};
    cout<<solution.ninjaTraining_memo(n,points)<<endl;
    cout<<solution.ninjaTraining_tabu(n,points);
    return 0;
}