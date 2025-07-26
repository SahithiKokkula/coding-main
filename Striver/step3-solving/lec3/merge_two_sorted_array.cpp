#include<bits/stdc++.h>
using namespace std;
void merge_array(vector <int>&arr1,vector<int>&arr2){
    int n1=arr1.size();
    int n2=arr2.size();
    int i=0;
    int j=0;
    while(i<n1){
        if(arr1[i]<=arr2[j]){
            i++;
        }
        else if (arr1[i]>arr2[j]){
            swap(arr1[i],arr2[j]);
            i++;
            int it=j;
            while(it+1<n2 && arr2[it]>arr2[it+1]){
                swap(arr2[it],arr2[it+1]);
                it++;
            }
        }
    }
    return;

}


// Gap method
void swapIfGreater(vector <int>&arr1,vector<int>&arr2,int idx1,int idx2){
    if (arr1[idx1]>arr2[idx2]){
        swap(arr1[idx1],arr2[idx2]);
    }
    return;
}
void merge_array_gap_method(vector <int>&arr1,vector<int>&arr2,int n,int m){
    int len = n+m;
    int gap = len / 2 + len % 2;
    while(gap>0){
        int left = 0;
        int right = left + gap;
        while(right < len){
            // both pointer in diff arr
            if (left < m && right >= m){
                swapIfGreater(arr1,arr2,left,right-m);
            }
            // both pointer in right arr 
            else if (left >=m){
                swapIfGreater(arr2,arr2,left-m,right-m);
            }
            // both pointer in left arr
            else if (right < m){
                swapIfGreater(arr1,arr1,left,right);

            }
            left ++;
            right ++;
        }
        if (gap == 1) break;
        gap = (gap  / 2) + (gap % 2);
    }
}
 



int main(){
    int n1,n2;
    cin>>n1>>n2;
    vector<int>arr1;
    vector<int>arr2;
    int num;
    for (int i=0;i<n1;i++){
        cin>>num;
        arr1.emplace_back(num);
    }
    for (int i=0;i<n2;i++){
        cin>>num;
        arr2.emplace_back(num);
    }
    merge_array(arr1,arr2);
    merge_array_gap_method(arr1,arr2,n2,n1);
    
    for (auto it:arr1){
        cout<<it<<" ";
    }
    cout<<endl;
    for (auto it:arr2){
        cout<<it<<" ";
    }

    return 0;
}