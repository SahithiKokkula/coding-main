#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long sum = 0;
        int odds = 0;
        int evens = 0;
        int num;
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            cin >> num;
            if(num % 2 == 1) {
                odds++;
            } else {
                evens++;
            }
            sum += num;
            maxi = max(maxi, num);
        }
        if(evens == 0 || odds == 0) {
            cout << maxi << endl;
        } else {
            long long possible = sum - odds + 1;
            cout << max((long long)maxi, possible) << endl;
        }
    }
    return 0;
}