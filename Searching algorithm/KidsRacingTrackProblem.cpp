/*
A new racing track for kids is being built in New York with 'n' starting spots. The spots are
located along a straight line at positions x1, x2 ... xn(xi <= 10^9). For each 'i', xi+1 > xi.
At a time only 'm' children are allowed to enter the race. Since the race track is for kids, they
may run into each other while running. To prevent this, we want to choose the starting spots
such that the minimum distance between any two of them is as large as possible. What is
the largest minimum distance?

The first line of input will contain the value of n, the number of starting spots.
The second line of input will contain the n numbers denoting the location of each spot.
The third line will contain the value of m, number of children.

Input
5
1 2 4 8 9
3
Output
3

*/



#include<iostream>
#include<vector>
bool checkpath(std::vector<int>&arr,int n,int m,int dist){
    int req=1;
    int cdist=0;
    int laststu=arr[0];
    for (int i=1;i<n;i++){
        if(arr[i]-laststu>=dist){
            req++;
            laststu=arr[i];
            if(req==m) return true;
        }
    }
    return false;
}
int mindist(std::vector<int>&arr,int n,int m){
    int li=arr[0];
    int hi=arr[n-1]-arr[0];
    int ans=-1;
    while(li<=hi){
        int mid=li+(hi-li)/2;
        if(checkpath(arr,n,m,mid)){
            ans=mid;
            li=mid+1;
        }
        else{
            hi=mid-1;
        }
    }
    return ans;
}
int main(){
    int n;
    std::cout<<"Enter number of tracks";
    std::cin>>n;
    std::vector<int>arr;
    for(int i=0;i<n;i++){
        int ele;
        std::cin>>ele;
        arr.push_back(ele);
    }
    int m;
    std::cout<<"Enter no of student";
    std::cin>>m;
    std::cout<<mindist(arr,n,m);
    return 0;
}