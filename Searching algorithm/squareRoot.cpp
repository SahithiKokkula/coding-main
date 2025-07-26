/*Find the square root of the given non negative value x. Round it off to the nearest
floor integer value.*/

#include<iostream>
int sq_root(int l,int r,int num, int ans=-1){
    if(l>r) return ans;
    int mid=l+(r-l)/2;
    if(mid*mid>num) sq_root(l,mid-1,num,ans);
    else if(mid*mid<=num) {
        ans=mid;
        sq_root(mid+1,r,num,ans);
    }
}
int main(){
    int n;
    std::cout<<"Enter the number: ";
    std::cin>>n;
    std::cout<<sq_root(1,n,n);
    return 0;
}
