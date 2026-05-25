#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {2,1,5,4,3};
    int n = arr.size();

    int profit = 0;
    int mini = arr[0];
    int diff = 0;

    for(int i=1;i<n;i++){
        diff = arr[i] - mini; 
        profit = max(profit,diff);
        mini = min(mini,arr[i]);
    }
    cout<<profit;
}