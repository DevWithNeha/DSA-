#include<bits/stdc++.h>
using namespace std;
void kthLargestEleStream(vector<int> &arr,int k){
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int x:arr){
        pq.push(x);

        if(pq.size() > k){
            pq.pop();
        }

        if(pq.size()<k){
            cout<< -1 <<" ";
        } else{
            cout<<pq.top()<<" ";
        }
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5};

    int k = 4;

    kthLargestEleStream(arr,k);
}