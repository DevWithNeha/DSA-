// sorted h toh bs aur heap dono
//ye sorted h toh bs use ki huu

/*

#include<bits/stdc++.h>
using namespace std;
vector<int> kthClosestEle(vector<int>& arr,int k,int x){
    int n = arr.size();

    int low = 0;
    int high = n-k;

    while(low<=high){
        int mid = (low+high)/2;

        if(x-arr[mid] > arr[mid+k]-x){
            low = mid+1;
        } else{
            high = mid-1;
        }
    }
    vector<int> ans;

    for(int i = low;i<low+k;i++){
        ans.push_back(arr[i]);
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,5};
    int k = 4;
    int x = 3;

    vector<int> ans = kthClosestEle(arr,k,x);

    for(int x:ans){
        cout<<x<<" ";
    }
}

*/

// unsorted array ke liye heap 

#include<bits/stdc++.h>
using namespace std;

vector<int> kthClosestEle(vector<int>& arr,int k,int x){
    priority_queue<pair<int,int>> pq;

    for(int i=0;i<arr.size();i++){

        int diff = abs(arr[i] - x);

        pq.push({diff,arr[i]});

        if(pq.size() > k){
            pq.pop();
        }
    }
    vector<int> ans;

    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    sort(ans.begin(),ans.end());

    return ans;
}

int main(){
    vector<int> arr = {2,4,6,8,3,2};
    int k = 3;
    int x = 3;

    vector<int> ans = kthClosestEle(arr,k,x);

    for(int x:ans){
        cout<<x<<" ";
    }
}