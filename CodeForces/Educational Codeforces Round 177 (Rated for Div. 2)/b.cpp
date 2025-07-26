#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
cin >> t;               
while(t--){
    int n, k;
    long long x;
    cin >> n >> k >> x; 
    
    vector<long long> sums(n, 0);
    for(int i = 0; i < n; i++){
        int a_i;
        cin >> a_i;
        if(i == 0) sums[i] = a_i;
        else        sums[i] = sums[i - 1] + a_i;
    }
    
    long long totalSum = sums[n - 1];
    
    int idx = 0;
    
    
    if(x > totalSum){
        long long repetition_needed = x / totalSum;  
        
        if(repetition_needed > k){
            cout << 0 << endl;
            continue;
        }
        
        long long rem_sum = x - repetition_needed * totalSum;
        
        if(repetition_needed == k && rem_sum > 0){
            cout << 0 << endl;
            continue;
        }
        else if(repetition_needed == k && rem_sum == 0){
            cout << 1 << endl;
            continue;
        }
        
        
        for(int i = n - 2; i >= 0; i--){
            long long suffixSum = totalSum - sums[i]; 
            if(suffixSum >= rem_sum){
                idx = i + 1;  
                break;
            }
        }
        
        k = k - repetition_needed; 
        
        cout << idx + n * (k - 1) + 1 << endl;
    }
    
    else if(x == totalSum){
        cout << 1 << endl;
    }
    
    else{
        
        for(int i = n - 2; i >= 0; i--){
            long long suffixSum = totalSum - sums[i];
            if(suffixSum >= x){
                idx = i + 1; 
                break;
            }
        }
        cout << idx + n * (k - 1) + 1 << endl;
    }
}

}