#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int> &arr,int days,int m,int k){
    int cnt = 0;
    int noOfb = 0;

    for(int i=0;i<arr.size();i++){
        if(arr[i]<=days){
            cnt++;
        }
        else{
            noOfb += (cnt/k);
            cnt = 0;
        }
    }
    noOfb += (cnt/k);

    return noOfb >= m;
}

int roseGarden(vector<int> &arr,int m ,int k){
    int val = 1LL * m * k;

    if(val > arr.size()) return -1;

    int mini = INT_MAX , maxi = INT_MIN;
    
    for(int i=0; i<arr.size();i++){
        mini = min(mini,arr[i]);
        maxi = max(maxi,arr[i]);
    }

    int low = mini;
    int high = maxi;

    while(low<=high){
        int mid = (low+high)/2;

        if(possible(arr,mid,m,k)){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

int main(){
    vector<int> arr = {7,7,7,7,13,11,12,7};
    int m = 2;
    int k = 3;

    int ans = roseGarden(arr,m,k);

    cout<< " minimum days = "<<ans;

    return 0;
}