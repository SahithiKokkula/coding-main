#include<bits/stdc++.h>
using namespace std;
class Solution{

public:
    vector<long long int> twoOddNum(vector<long long int> Arr, long long int N)      {
        long long int XOR_all = 0;
        for (int i=0;i<N;i++){
            XOR_all = XOR_all^Arr[i];
        }
        long long int diff_bit = (XOR_all&(XOR_all-1))^XOR_all;
        long long bucket1 = 0;
        long long bucket2 = 0;
        for(int i = 0; i<N;i++){
            if ((Arr[i] & diff_bit) != 0 ){
                bucket1 = bucket1 ^ Arr[i];
            }
            else{
                bucket2 = bucket2 ^ Arr[i];
            }
        }
        vector<long long int> result(2);
        if (bucket1>bucket2){
            result[0] = bucket2;
            result[1] = bucket1;
        }
        else{
            result[0] = bucket1;
            result[1] = bucket2;
        }
        return result;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution solution;
    int N;
    cin>>N;
    vector<long long int>Arr(N);
    for(int i=0;i<N;i++){
        cin>>Arr[i];
    }
    vector<long long int> result = solution.twoOddNum(Arr,N);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}