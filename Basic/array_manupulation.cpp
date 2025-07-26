#include<iostream>
using namespace std;
int main(){
    int array[]={1,1,2,2,3,4,5,6,7,8,9,9,10,12,14,10,13,14,12,8,5,7,4,6,3};
    int size=sizeof(array)/sizeof(array[0]);
    int unique=0;
    // cout<<size;
    int find=0;
    for (int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            if(i!=j){
                if (array[j]==array[i]){
                    find=0;
                    break;
                }
                else{
                    find=1;
                    unique=array[i];
                }
            }
        }
        if (find==1){
            break;
        }
        
        
        
    }
    cout<<"unique number is :"<<unique;
}