// #include<iostream>
// using namespace std;
// int parttion(int arr[],int l, int r){
//     int pivot=arr[r];
//     int i=l-1;
//     int j=l;
//     for(j;j<r;j++){
//         if(arr[j]<pivot) swap(arr[++i],arr[j]);
//     }
//     swap(arr[i+1],arr[l]);
//     return i+1;
// }
// int kthsmalles(int arr[],int k,int l, int r){
//     int pi=parttion(arr,l, r);
//     if(pi-l==k-1) return arr[pi];
//     else if(pi-l>k-1) kthsmalles(arr,k,l,pi-1);
//     else if(pi-1<k-1) kthsmalles(arr,k-(pi-l+1),pi+1,r);
// }
// int main(){
//     int k;
//     cin>>k;
//     int arr[]={9,8,7,6,5,4,41,682,68,546,54,5};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     cout<<kthsmalles(arr,k,0,n);
//     return 0;
// }






#include<iostream>
void merge(int arr1[],int arr2[],int n1,int n2){
    int arr[n1+n2]={0};
    int k=0;
    int i=0;
    int j=0;
    // for(int i=0;i<n2;i++){
    //     std::cout<<arr2[i]<<" ";
    // }
    while(i<n1 || j<n2){
        if(arr1[i]<arr2[j]){ 
            // std::cout<<arr1[i]<<" ";
            arr[k]=arr[i++];
            k++;
            // std::cout<<arr1[i-1]<<" ";
        }
        else {
            // std::cout<<arr2[j]<<" ";
            arr[k]=arr[j++];
            k++;
            // std::cout<<arr2[j-1]<<" ";
        }
    }
    // while(i<n1){
        
    //     // std::cout<<arr1[i]<<" ";
    //     arr[k]=arr1[i++];
        
    //     std::cout<<arr1[i-1]<<" ";
    // }
    // while(j<n2){
    //     // std::cout<<arr2[j]<<" ";
    //     arr[k]=arr2[j++];
        
    //     std::cout<<arr2[j-1]<<" ";
    // }
    std::cout<<std::endl;
    for(int i=0;i<n1+n2;i++){
        std::cout<<arr[i]<<" ";
    }
}
int main(){
    int arr1[]={1,4,7,9};
    int arr2[]={2,3,5,6,8};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    int arr[n1+n2];
    merge(arr1,arr2,n1,n2);
    
    return 0;
}