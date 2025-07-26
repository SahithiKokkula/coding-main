#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%2!=0){
            cout<<"NO"<<endl;
        }
        else{
            int check = 1;
            int num;
            vector<int>arr;
            for(int i=0;i<n;i++){
                cin>>num;
                arr.emplace_back(num);
            }
            sort(arr.begin(),arr.end());
            int curr;
            for (int i = 0;i < n ; i = i+2){
                curr = arr[i];
                int j;
                if (i+1<n && curr == arr[i+1]){
                    if(i+2<n){
                        j = i+2;
                        while(j<n && arr[j]==curr){
                            arr[j]++;
                            j++;
                        }
                    }
                }
                else{
                    check = -1;
                }
                
            }
            if (check == 1 ){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }

    }
}