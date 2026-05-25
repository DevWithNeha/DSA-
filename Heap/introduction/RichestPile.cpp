// brute force

/*

#include<bits/stdc++.h>
using namespace std;

int richestPile(vector<int> &arr , int k){
    int n = arr.size();

    while(k--){
        int maxi = INT_MIN;
        int index = -1;

        for(int i=0;i<arr.size();i++){
            if(arr[i] > maxi){
                maxi = arr[i];
                index = i;
            }
        }
        arr[index] = sqrt(arr[index]);
    }

    int sum = 0;

    for(int x:arr){
        sum += x;
    }
    return sum;
}

int main(){
    vector<int> arr = {25,64,9,4,100};

    int k = 4;

    cout<<richestPile(arr,k);
}

*/

// optimal sol

#include<bits/stdc++.h>
using namespace std;
int richestPile(vector<int> &arr,int k){
    priority_queue<int> pq;

    for(int x:arr){
        pq.push(x);
    }

    while(k--){
        int first = pq.top();
        pq.pop();

        int total = sqrt(first);

        pq.push(total);

    }

    long long sum = 0;

    while(!pq.empty()){
        sum += pq.top();
        pq.pop();
    }

    return sum;
}

int main(){
    vector<int> arr = {25,64,9,4,100};
    int k = 4;

    cout<<richestPile(arr,k);
}