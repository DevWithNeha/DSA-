// brute force

/*

#include<bits/stdc++.h>
using namespace std;
int kthSmallestEle(vector<int>& arr,int k){
    sort(arr.begin(),arr.end());

    return arr[k-1];
}

int main(){
    vector<int> arr = {2,5,4,6,1,2};

    int k = 4;

    cout<<kthSmallestEle(arr,k);
}
// better solution

/*
#include<bits/stdc++.h>
using namespace std;

int kthSmallestEle(vector<int>& arr,int k){
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int x:arr){
        pq.push(x);
    }

    int first;

    while(k--){
        first = pq.top();
        pq.pop();

    }
    return first;
}

int main(){
    vector<int> arr = {2,5,4,6,1,2};

    int k = 4;

    cout<<kthSmallestEle(arr,k);
}

*/

// using max heap

/*
#include<bits/stdc++.h>
using namespace std;

int kthsmallestele(vector<int> &arr,int k){
    priority_queue<int> pq;

    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }

    for(int i=k;i<arr.size();i++){
        if(arr[i] < pq.top()){

            pq.pop();

            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main(){
    vector<int> arr = {2,5,4,6,1,2};

    int k = 4;

    cout<<kthsmallestele(arr,k);
}

*/

// using binary search

#include<bits/stdc++.h>
using namespace std;

int lessele(vector<int>& arr,int mid){
    int count = 0;

    for(int x:arr){
        if(x<=mid)
        count++;
    }
    return count;
}

int kthsmallestele(vector<int> &arr,int k){
    int low = *min_element(arr.begin(),arr.end());
    int high = *max_element(arr.begin(),arr.end());

    while(low<=high){
        int mid = (low+high)/2;

        int count = lessele(arr,mid);

        if(count < k){
            low = mid+1;
        } else{
            high = mid-1;
        }
    }
    return low;
}


int main(){
    vector<int> arr = {1,2,3,4,5,6};
    int k = 4;

    cout<<kthsmallestele(arr,k);
}