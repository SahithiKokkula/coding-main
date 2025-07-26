// Way 1



#include<iostream>
using namespace std;
int fac(int n,int factorial=1){
    if (n==0){
        return factorial;
    }
    else{
        factorial=n*fac(n-1);
    }
}
int ncr_ans=1;
int ncr(int n,int r){
    ncr_ans=fac(n)/(fac(r)*fac(n-r));
    return ncr_ans;
}
int main(){
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
    for (int i=0;i<n;i++){
        for (int j=0;j<i+1;j++){
            cout<<ncr(i,j)<<" ";
        }
        cout<<endl;
    }
    return 0;
}




// Way 2



#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of rows: ";
    cin>>n;
	vector <vector<int>> vec(n,vector<int>(n));
	for(int i=0;i<n;i++){
		for (int j=0;j<i+1;j++){
			if(j==0||j==i){
				vec[i][j]=1;
			}
			else{
				vec[i][j]=vec[i-1][j]+vec[i-1][j-1];
			}
		}
	}
	for (int i=0;i<n;i++){
		for(int j=0;j<i+1;j++){
			cout<<vec[i][j]<<" ";
		}
		cout<<endl;
	}
    return 0;
} 
