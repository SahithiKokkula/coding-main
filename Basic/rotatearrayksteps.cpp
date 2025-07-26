#include<iostream>
using namespace std;

int main(){
    int array[]={1,3,4,5,7,546,5,5,15,5,5,6,5,5,154648,45,4864,65,46,4835,65,468,46,486,453,168,486,48,84,5,65468,46435,3,46,6,18,4384};
    int size=(sizeof(array)/sizeof(array[0]));  
    int k;
    cout<<"enter number of steps :";
    cin>>k;
    for (int j =1;j<=k;j++){
        int last_element=array[size-1];
        for (int i=size-1;i>=0;i--){
            if (i!=0){
                array[i]=array[i-1];                  
            }
            else{
                array[i]=last_element;
            }
        }
    }
    for (int i=0;i<size;i++){
        cout<<array[i]<<endl;
    }
}