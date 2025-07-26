/*

You have 'n'(n <= 10A5) boxes of chocolate. Each box contains a[i] (a[i] <= 10000) chocolates. You
need to distribute these boxes among 'm' students such that the maximum number of chocolates
allocated to a student is minimum.
a. One box will be allocated to exactly one student.
b. All the boxes should be allocated.
c. Each student has to be allocated at least one box.
d. Allotment should be in contiguous order, for instance, a student cannot be allocated box 1 and
box 3, skipping box 2.
Calculate and return that minimum possible number.
Assume that it is always possible to distribute the chocolates.

The first line of input will contain the value of n, the number of boxes.
The second line of input will contain the n numbers denoting the number of chocolates in each box.
The third line will contain the m, number of students.

Input
4
12 34 67 90
2
Output
113
*/


#include<iostream>
int checkerfn(int chocolates[],int n,int maxcho,int size){
    int req=1;
    int curr=0;
    for (int i=0;i<size;i++){
        if(chocolates[i]>maxcho) return 0;
        if(curr+chocolates[i]>maxcho){
            req++;
            curr=chocolates[i];
            if(req>n) return 0;
        }
        else{
            curr+=chocolates[i];
        }
    }
    return 1;
}
int min_of_max_chocolates(int chocolates[],int n,int size){
    int total=0;
    for (int i=0;i<size;i++){
        total+=chocolates[i];
    }
    int ans=-1;
    int lo=chocolates[0];
    int hi=total;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        int check=checkerfn(chocolates,n,mid,size);
        if(check==1) {
            ans=mid;
            hi=mid-1;
        }
        else if(check==0) lo=mid+1;
    }
    return ans;
}
int main(){
    int n;
    std::cout<<"Enter number of students: ";
    std::cin>>n;
    int chocolates[]={10,20,30};
    int size=sizeof(chocolates)/sizeof(chocolates[0]);
    std::cout<<min_of_max_chocolates(chocolates,n,size);
    return 0;
}