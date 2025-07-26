// #include<iostream>
// using namespace std;

// array 
// int main(){
//     int n;
//     cout<<"Enter number of elements:";
//     cin>>n;
//     int array[n];
//     for(int i=0;i<n;i++){
//         cout<<"Enter number "<<i+1<<":"<<endl;
//         cin>>array[i];
//     }
//     int err =-1;
//     for(int i=0;i<n-1;i++){
//         if (array[i+1]<array[i]){
//             err=1;
//             break;
//         }
//     }
//     if (err==1){
//         cout<<"not sorted";
//     }
//     else{
//         cout<<"sorted";
//     }
//     return 0;
// }




// vector 

// #include<vector>
// int main(){
//     int n;
//     cout<<"Enter number of elements:";
//     cin>>n;
//     vector <int> v(n);
//     for(int i=0;i<n;i++){
//         cout<<"Enter number "<<i+1<<":"<<endl;
//         cin>>v[i];
//     }
//     int err =-1;
//     for(int i=0;i<n-1;i++){
//         if (v[i+1]<v[i]){
//             err=1;
//             break;
//         }
//     }
//     if (err==1){
//         cout<<"not sorted";
//     }
//     else{
//         cout<<"sorted";
//     }
//     return 0;  

// }






#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        cout<<"Enter number "<<i+1<<":"<<endl;
        cin>>v[i];
    }
    int s_even=0;
    int s_odd=0;
    for(int i=0;i<n;i++){
        if (i%2==0){
            s_even+=v[i];
        }
        else{
            s_odd+=v[i];
        }
    }
    cout<<s_even-s_odd;
    return 0;  




    // v.push_back(5);
    // cout<<endl<<"size"<<v.size();
}