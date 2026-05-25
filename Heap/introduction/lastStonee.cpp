// brute force

/*
#include<bits/stdc++.h>
using namespace std;

int lastStone(vector<int>& arr){
    int n = arr.size();

    while(arr.size() > 1){

        sort(arr.begin(),arr.end());

        int first = arr[n-1];
        int second = arr[n-2];

        arr.pop_back();
        arr.pop_back();

        if(first!=second){
            arr.push_back(first-second);
        }
        if(arr.empty()) return 0;

        return arr[0];
        
    }
}

int main(){
    vector<int> arr = {2,7,4,1,8,1};
    
    cout<<lastStone(arr);
}

*/

// optimal solution

#include<bits/stdc++.h>
using namespace std;

int lastStone(vector<int>& stones){
    priority_queue<int> pq;

    for(int x:stones){
        pq.push(x);
    }

    while(pq.size()>1){
        int first = pq.top();
        pq.pop();

        int second = pq.top();
        pq.pop();

        if(first != second){
            pq.push(first-second);
        }
    }
    if(pq.empty()) return 0;

    return pq.top();
}

int main(){
    vector<int> stones = {2,7,4,1,8,1};

    cout<<lastStone(stones);
}