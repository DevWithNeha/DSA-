// brute force

/*
#include<bits/stdc++.h>
using namespace std;

int mincost(vector<int>& arr){


    int cost = 0;

    while(arr.size()>1){

    sort(arr.begin(),arr.end());

    int first = arr[0];
    int second = arr[1];

    int sum = first + second;

    cost += sum;

    arr.erase(arr.begin());

    arr.erase(arr.begin());

    arr.push_back(sum);

    }
    return cost;
}

int main(){
    vector<int> arr = {4,3,2,6};

    cout<<mincost(arr);
}

*/

// optimal sol

#include<bits/stdc++.h>
using namespace std;

int mincost(vector<int>& arr){
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int x:arr){
        pq.push(x);
    }

    int cost = 0;

    while(pq.size() > 1){
        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        int sum = first+second;

        cost += sum;

        pq.push(sum);
    }
    return cost;
}

int main(){
    vector<int> arr = {4,2,7,6,9};

    cout<<mincost(arr);
}

