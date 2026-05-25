#include<bits/stdc++.h>
using namespace std;

int profitmax(vector<int>& arr,int k){
    priority_queue<int> pq;

    int profit = 0;

    for(int x:arr){
        pq.push(x);
    }

    while(k--){
        int top = pq.top();
        pq.pop();

        profit += top;
        if(top - 1 > 0){
            pq.push(top-1);
            
        }
    }
    return profit;
}

int main(){
    vector<int> arr = {6,4,2,3};

    int k = 4;

    cout<<profitmax(arr,k);
}
