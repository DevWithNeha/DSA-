#include<bits/stdc++.h>
using namespace std;

long long merge(vector<int> &arr,int low,int mid,int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    long long cnt = 0;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        } else{
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low;i<=high;i++){
        arr[i] = temp[i-low];
    }
    return cnt;
}

long long mergesort(vector<int> &arr,int low,int high){
    long long cnt = 0;
    if(low<high){
        int mid = (low+high)/2;
        cnt += mergesort(arr,low,mid);
        cnt += mergesort(arr,mid+1,high);
        cnt += merge(arr,low,mid,high);
    }
    return cnt;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<mergesort(arr,0,n-1);
}
