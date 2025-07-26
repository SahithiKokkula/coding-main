#include<iostream>
void p_array(int *arr,int len, int idx=0){
    if (idx==len) return;
    std::cout<<*(arr+idx)<<"\n";
    p_array(arr,len,idx+1);

}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int len=sizeof(arr)/sizeof(arr[0]);
    p_array(arr,len);
    return 0;
}