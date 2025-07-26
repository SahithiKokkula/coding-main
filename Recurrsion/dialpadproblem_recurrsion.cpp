/*Given a string containing digits from 2-9 inclusive, return all possible letter
combinations that the number could represent. Return the answer in any order.*/
#include<iostream>
#include<vector>
using namespace std;
void f1(vector<string>&result,vector<vector<string>>dial_pad,int n1, int n2,int idx1=0,int idx2=0,int ptr1=0,int ptr2=0){
    if(ptr1==0&&ptr2==0){
        ptr1=dial_pad[n1].size();
        ptr2=dial_pad[n2].size();
    }
    if(idx1==ptr1) return;
    result.push_back(dial_pad[n1][idx1]+dial_pad[n2][idx2]);
    idx2++;
    if(idx2==ptr2){
        idx1++;
        idx2=0;
    }
    f1(result,dial_pad,n1,n2,idx1,idx2,ptr1,ptr2);
}
void f2(vector<string>&result,vector<vector<string>>dial_pad,int n1, int idx,int ptr){

}
int main(){
    vector<vector<string>> dial_pad ={{},{},{"a","b","c"},{"d","e","f"},{"g","h","i"},{"j","k","l"},{"m","n","o"},{"p","q","r","s"},{"t","u","v"},{"w","x","y","z"}};
    vector<string>result;
    f1(result,dial_pad,9,7);
    for(string i:result){
        cout<<i<<endl;
    }
    return 0;
}