#include<iostream>
using namespace std;


// pairs
// int main(){
//     int array[]={3,4,1,2,6};
//     int target;
//     int size=5;
//     cout<<"Enter target :";
//     cin>>target;
//     int count =0;
//     for (int i=0;i<size;i++){
//         int b=target-array[i];
//         for (int j=i+1;j<size;j++){     
//             if(array[j]==b)
//             count++;
//         }
//     }
//     cout<<"Total number of pairs :"<<count;
// }




// triplets
int main(){
    int array[]={3,1,2,4,0,6};
    int size=6;
    int target;
    cout<<"Enter target :";
    cin>>target;
    int count =0;
    for (int i=0;i<size;i++){
        int b=target-array[i];
        for (int j=i+1;j<size;j++){
            int c=b-array[j];
            for (int k=j+1;k<size;k++){     
                if(array[k]==c)
                // cout<<array[i]<<"+"<<array[j]<<"+"<<array[k]<<endl;
                count++;
            }
        }
    }
    cout<<"Total number of triplets :"<<count;
}