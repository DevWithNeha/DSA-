#include<bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>& arr,int orders){
    priority_queue<int> pq;

    for(int x:arr){
        pq.push(x);
    }

    int profit = 0;

    while(orders--){
        int first = pq.top();
        pq.pop();

        profit += first;

        if(first - 1 != 0){
            pq.push(first-1);
        }
    }
return profit;
}

int main(){
    vector<int> arr = {4,8};
    int orders = 4;

    cout<<maxProfit(arr,orders);
}