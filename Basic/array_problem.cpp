#include<iostream>
#include<vector>
using namespace std;


// problem 1

// int main(){
//     vector <int> v;
//     int n;
//     cout<<"Enter number of elements: ";
//     cin>>n;
//     for (int i=0;i<n;i++){
//         int ele;
//         cout<<"Enter element "<<i+1<<": ";
//         cin>>ele;
//         v.push_back(ele);
//     }
//     int x;
//     int find=-1;
//     cout<<"Enter the required sum :";
//     cin>>x;
//     for (int i=0;i<n;i++){
//         for (int j=i+1;j<n;j++){
//             if (v[i]+v[j]==x){
//                find=1;
//                break; 
//             }
//         }
//     }
//     if (find==1){
//         cout<<"Pair found";
//     }
//     else{
//         cout<<"Not found";
//     }
//     return 0;
// }



// problem 2      -3   -2    1   5    9

int main(){
    vector<int> arr;
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    for (int i=0;i<n;i++){
        int ele;
        cout<<"Enter element "<<i+1<<": ";
        cin>>ele;
        arr.push_back(ele);
    }
    int r_ptr=arr.size()-1;
    int l_ptr=0;
    while(l_ptr<r_ptr){

    }
    return 0;
}