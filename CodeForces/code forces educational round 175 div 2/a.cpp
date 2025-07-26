#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int rem = (n/15);
        int ans = 3*rem;
        if ( n - 15*(rem) == 0 ) {ans = ans + 1;}
        else if(n - 15*(rem) == 1 ){ ans = ans + 2;}
        else if (n - 15*(rem) >= 2) {{ans = ans + 3;}}
        cout<<ans<<endl;
    }
}