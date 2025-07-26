#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
    sort(arr.begin(),arr.end());
    vector<vector<int>> merged;
    int n=arr.size();
    int a,b;
    int i=0;

    // Optimal loop 
    for (int i=0;i<n;i++){
        if(merged.empty()|| arr[i][0]>merged.back()[1]){
            merged.push_back(arr[i]);
        }
        else{
            merged.back()[1]= max(merged.back()[1],arr[i][1]);
        }
    }


    // Brute force loop 

	// for (int i=0;i<n;i++){
	// 	a=arr[i][0];
    //     b=arr[i][1];
    //     if (!merged.empty() && merged.back()[1]>=b) continue;
    //     for(int j=i+1;j<n;j++){
    //         if (arr[j][0]<=b) b = max(arr[j][1],b);
    //         else break;
    //     }
    //     merged.push_back({a,b});

	// }


    return merged;
}
int main(){
    int n;
    cin>>n;
    int a,b;
    vector<vector<int>>nums;
    for (int i=0;i<n;i++){
        cin>>a>>b;
        nums[i][0]=a;
        nums[i][1]=b;
    }
    vector<vector<int>> merged = mergeOverlappingIntervals(nums);
    for (auto it:merged){
        cout<<"("<<it[0]<<","<<it[1]<<")"<<endl;
    }
    return 0;
}