#include<bits/stdc++.h>
using namespace std;
struct Item{
    int value;
    int weight;
};
class Solution{
private:
    bool static comp(Item a, Item b){
        double r1 = (double) a.value / (double) a.weight;
        double r2 = (double) b.value / (double) b.weight;
        return r1 > r2;
    }
public:
    double fractionalKnapsack(int total_weight, vector<Item>arr, int n){
        sort(arr.begin(), arr.end(), comp);

        int currWeight = 0;
        double final_value = 0;
        for(int i = 0 ;i < n ; i++){
            if (currWeight + arr[i].weight <= total_weight){
                currWeight += arr[i].weight;
                final_value += arr[i].value;
            }
            else{
                int remaining = total_weight - currWeight;
                final_value += ((double) arr[i].value / (double) arr[i].weight ) * (double) remaining;
                break;
            }
        }
        return final_value;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 3;
    int total_weight = 50;
    vector<Item>arr = { {100,20},{60,10},{120,30} };
    Solution solution;
    double result = solution.fractionalKnapsack(total_weight,arr,n);
    cout<<result;
    return 0;
}