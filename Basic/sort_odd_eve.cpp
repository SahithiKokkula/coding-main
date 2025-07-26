#include<iostream>
#include<vector>
using namespace std;
void sortOddEve(vector<int> &v){
    int l_pointer=0;
    int r_pointer=v.size()-1;
    while(l_pointer<r_pointer){
        if (v[l_pointer]%2==1 && v[r_pointer]%2==0){
            swap(v[l_pointer],v[r_pointer]);
            l_pointer++;r_pointer--;
        }
        else if (v[l_pointer]%2==0){
            l_pointer++;
        }
        else if (v[r_pointer]%2==0){
            r_pointer--;
        }
        // cout<<l_pointer<<" "<<r_pointer;

    }
    return;
}
int main(){
    vector<int> v;
    int n;
    int ele;
    cout<<"Enter number of elements :";
    cin>>n;
    for (int i =0;i<n;i++){
        cin>>ele;
        v.push_back(ele);
    }
    sortOddEve(v);
    for (int ele:v){
        cout<<ele<<" ";
    }
}