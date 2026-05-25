#include<bits/stdc++.h>
using namespace std;

int CountParts(vector<int> &arr,int maxvalue){
    int parts = 1;
    int sum = 0;

    for(int i=0;i<arr.size();i++){
        if(sum + arr[i] <= maxvalue){
            sum += arr[i];
        } else{
            parts++;
            sum = arr[i];
        }
    }
    return parts;
}
int SplitArray(vector<int> &arr,int k){
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    int ans = 0;

    while(low<=high){
        int mid = (low+high)/2;

        int parts = CountParts(arr,mid);

        if(parts <= k){
            ans = mid;
            high = mid-1;
        } else{
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {7,2,5,10,8};
    int k = 2;  // mtlb 2 parts me karna h 

    cout<<SplitArray(arr,k);
    
}