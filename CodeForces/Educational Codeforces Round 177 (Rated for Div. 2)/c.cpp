#include<bits/stdc++.h>
using namespace std;



int solve1(vector<int>arr,int n,map<int,int>arr_map){
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        if (arr[i] == 0){
            int reqno = i+1;
            while(arr_map.find(reqno) != arr_map.end()){
                int index = arr_map[reqno];
                arr[reqno-1] = reqno;
                arr[index] = 0;
                arr_map[reqno] = reqno-1;
                reqno=index+1;
                count++;
            }
            arr[reqno-1] = reqno;
            count++;
        }
    }
    return count;
}


vector<int> solve(int n,vector<int>&p,vector<int>&d,map<int,int>mp){
    vector<int>result(n);
    for(int i = 0; i < n ; i++){
        mp.erase(mp.find(p[d[i]-1]));
        p[d[i]-1] = 0;
        if (i > 0 && result[i-1] == n){
            result[i] = result[i-1];
        }
        else{
            result[i] = solve1(p,n,mp);
        }
    }
    return result;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>p(n);
        vector<int>d(n);
        int num;
        map<int,int>arr_map;
        for(int i = 0 ;i < n; i++){
            cin>>num;
            p[i]= num;
            if(p[i]!=0){
                arr_map[p[i]] = i;
            }
        }
        for(int i = 0 ;i < n ; i++){
            cin>>num;
            d[i] = num;
        }

        vector<int>result = solve(n,p,d,arr_map);
        for(auto it:result){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    return 0;
}