/*Find the first occurrence of a given element x, given that the given array is sorted.
If no occurrence of x is found then return -1.*/

// Method-1

// #include<iostream>
// int index_improvement(int arr[],int idx,int num){
//     while(idx!=0){
//         if(arr[idx-1]==num) idx--;
//         else return idx;
//     }
//     return idx;
// }
// int binary_search(int arr[],int num,int l,int r){
//     if(l>r) return -1;
//     int mid=l+(r-l)/2; //  (r+l)/2
//     if(arr[mid]==num) return index_improvement(arr,mid,num);
//     else if(arr[mid]>num) binary_search(arr,num,l,mid-1);
//     else if(arr[mid]<num) binary_search(arr,num,mid+1,r);
// }
// int main(){
//     int arr[]={2,2,2,2,2,3,3,5,5,5,6,6,6,7,7};
//     int num;
//     std::cout<<"Enter number to search";
//     std::cin>>num;
//     int n=sizeof(arr)/sizeof(arr[0]);
//     std::cout<<binary_search(arr,num,0,n-1);
//     return 0;
// }


// Method-2

#include<iostream>

int binary_search(int arr[],int num,int l,int r,int ans=-1){
    if(l>r) return ans;
    int mid=l+(r-l)/2; //  (r+l)/2
    if(arr[mid]==num) {
        ans=mid;
        binary_search(arr,num,l,mid-1,ans);
    }
    else if(arr[mid]>num) binary_search(arr,num,l,mid-1,ans);
    else if(arr[mid]<num) binary_search(arr,num,mid+1,r,ans);
    // return ans;
}
int main(){
    int arr[]={2,2,2,2,2,3,3,5,5,5,6,6,6,7,7};
    int num;
    std::cout<<"Enter number to search";
    std::cin>>num;
    int n=sizeof(arr)/sizeof(arr[0]);
    std::cout<<binary_search(arr,num,0,n-1);
    return 0;
}