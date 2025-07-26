#include<bits/stdc++.h>
using namespace std;
// vector<int> findUnion(vector<int> &a, vector<int> &b) {
//         int n1=a.size();
//         int n2=b.size();
//         int i=0;
//         int j=0;
//         int k=0;
//         vector<int>uarr;
//         while(i<n1 && j<n2){
            
//             if (a[i]>b[j] ){
//                 if (k==0){
//                     uarr.emplace_back(b[j++]);
//                     k++;
//                 }
//                 else{
//                     if(b[j]!=uarr[k-1]){
//                         uarr.emplace_back(b[j++]);
//                         k++;
//                     }
//                     else{
//                         j++;
//                     }
//                 }
//             }
//             else if (a[i]<b[j]){
//                 if (k==0){
//                     uarr.emplace_back(a[i++]);
//                     k++;
//                 }
//                 else{
//                     if(a[i]!=uarr[k-1]){
//                         uarr.emplace_back(a[i++]);
//                         k++;
//                     }else{
//                         i++;
//                     }
//                 }
//             }
//             else{
//                 if (k==0){
//                     uarr.emplace_back(a[i++]);
//                     j++;
//                     k++;
//                 }
//                 else{
//                     if(a[i]!=uarr[k-1]){
//                         uarr.emplace_back(a[i++]);
//                         j++;
//                         k++;
//                     }
//                     else{
//                         i++;
//                         j++;
//                     }
//                 }
//             }
//         }
//         while(i<n1){
//             if(uarr[k-1]==a[i]){
//                 i++;
//             }
//             else{
//                 uarr.emplace_back(a[i++]);
//             }
//         }
//         while(j<n2){
//             if(uarr[k-1]==b[j]){
//                 j++;
//             }
//             else{
//                 uarr.emplace_back(b[j++]);
//             }
//         }
//     return uarr;
// }



vector<int> findUnion(vector<int> &a, vector<int> &b) {
    int n1 = a.size(), n2 = b.size();
    int i = 0, j = 0;
    vector<int> uarr;

    while(i < n1 && j < n2) {
        if(!uarr.empty() && uarr.back() == a[i]) { i++; continue; }
        if(!uarr.empty() && uarr.back() == b[j]) { j++; continue; }

        if(a[i] < b[j]) {
            uarr.emplace_back(a[i++]);
        } else if(a[i] > b[j]) {
            uarr.emplace_back(b[j++]);
        } else {  
            uarr.emplace_back(a[i++]);
            j++;
        }
    }
    while(i < n1) {  
        if(uarr.empty() || uarr.back() != a[i]) {
            uarr.emplace_back(a[i]);
        }
        i++;
    }
    while(j < n2) {  
        if(uarr.empty() || uarr.back() != b[j]) {
            uarr.emplace_back(b[j]);
        }
        j++;
    }
    return uarr;
}

int main(){

    vector<int>a;
    vector<int>b;
    int n1,n2;
    cin>>n1>>n2;
    while(n1--){
        int num;
        cin>>num;
        a.emplace_back(num);
    }
    while(n2--){
        int num;
        cin>>num;
        b.emplace_back(num);
    }
    vector<int>unionarr=findUnion(a,b);
    for(auto it: unionarr){
        cout<<it<<" ";
    }

}