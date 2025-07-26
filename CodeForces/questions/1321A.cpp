#include<iostream>
#include<vector>
#include <climits>
#include<cmath>
using namespace std;
int contestForRobots(vector<int>&robo1,vector<int>&robo2){
    int ans = -1;

    
}
int main(){
    int n;
    cin>>n;
    int num;
    vector<int>robo1(n);
    vector<int>robo2(n);
    for (int i=0;i<n;i++){
        cin>>num;
        robo1[i]=num;
    }
    for (int i=0;i<n;i++){
        cin>>num;
        robo2[i]=num;
    }
    cout<<contestForRobots(robo1,robo2);
    return 0;
}