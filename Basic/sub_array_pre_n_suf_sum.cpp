#include<iostream>
#include<vector>
using namespace std;




// [1,1,1,3]
// presum=1
// sufsum=3
// left=0
// right=3
void check(vector<int> v){
    int l_pointer=0;
    int r_pointer=v.size()-1;
    int pre_sum=v[l_pointer];
    int suf_sum=v[r_pointer];
    while ((l_pointer+1)<=(r_pointer-1)){
        if (pre_sum<suf_sum){
            pre_sum+=v[++l_pointer];
        }
        else if (suf_sum<pre_sum){
            suf_sum+=v[--r_pointer];
        }
        else if (suf_sum==pre_sum){
            pre_sum+=v[++l_pointer];
            suf_sum+=v[--r_pointer];
        }
    }
    if (pre_sum==suf_sum){
        cout<<"Can be divided.";
    }
    else{
        cout<<"Can not be divided.";
    }
}
int main(){
    int n;
    cout<<"Enter number of elements: "<<endl;
    cin>>n;
    vector<int> v;
    for (int i=0;i<n;i++){
        int ele;
        cout<<"Enter element "<<i+1<<": "<<endl;
        cin>>ele;
        v.push_back(ele);
    }
    check(v);
    return 0;
}