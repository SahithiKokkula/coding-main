#include<iostream>
int binary_search(int arr[],int num,int l,int r){
    if(l>r) return -1;
    int mid=l+(r-l)/2; //  (r+l)/2
    if(arr[mid]==num) return mid;
    else if(arr[mid]>num) binary_search(arr,num,l,mid-1);
    else if(arr[mid]<num) binary_search(arr,num,mid+1,r);
}
int main(){
    int arr[]={2,13,15,22,28,35,46,59,68,79};
    int num;
    std::cout<<"Enter number to search";
    std::cin>>num;
    int n=sizeof(arr)/sizeof(arr[0]);
    std::cout<<binary_search(arr,num,0,n-1);
    return 0;
}





