#include<bits/stdc++.h>
using namespace std;

void pattern1(int n){
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<"* ";
        }
        cout<<"\n";
    }
}

void pattern2(int n){
    for(int i=0;i<n;i++){
        for (int j=0;j<2*i+n-i;j++){
            if (j<(n-i-1)){
                cout<<"  ";
            }
            else{
                cout<<"* ";
            }
        }
        cout<<"\n";
    }
}

void pattern3(int n){
    int mid;
    if (n%2==0){
        mid = n/2-1;
        for(int i=0;i<n;i++){
        for (int j=0;j<2*n-1;j++){
            if (i+j>=mid && j-i<=mid && i-j<=mid+1 && i+j<=3*mid+1){
                cout<<"* ";

            }
            else{
                cout<<"  ";
            }
            
        }
        cout<<"\n";
    }
    }
    else{
        mid = (n-1)/2;
        for(int i=0;i<n;i++){
            for (int j=0;j<2*n-1;j++){
                if (i+j>=mid && j-i<=mid && i-j<=mid && i+j<=3*mid){
                    cout<<"* ";

                }
                else{
                    cout<<"  ";
                }
                
            }
        cout<<"\n";
        }
    }
    
}

void pattern4(int n){
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            int top = i;
            int bottom = j;
            int right = (2*n - 2) - j;
            int left = (2*n - 2) - i;
            cout<<(n- min(min(top,bottom), min(left,right)))<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;
    // pattern1(n);
    // pattern2(n);
    // pattern3(n);
    pattern4(n);
}