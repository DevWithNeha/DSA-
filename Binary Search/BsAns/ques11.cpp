#include<bits/stdc++.h>
using namespace std;

int CountPainter(vector<int> &arr,int maxvalue){
    int painter = 1;
    int time = 0;

    for(int i=0;i<arr.size();i++){
        if(time+ arr[i] <= maxvalue){
            time += arr[i];
        } else{
            painter++;
            time = arr[i];
        }
    }
    return painter;
}
int painterpartition(vector<int> &arr,int k){
    int low = *max_element(arr.begin(),arr.end());
    int high = accumulate(arr.begin(),arr.end(),0);
    int ans = 0;

    while(low<=high){
        int mid = (low+high)/2;

        int painter = CountPainter(arr,mid);

        if(painter <= k){
            ans = mid;
            high = mid-1;
        } else{
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {10,20,30,40};
    int k = 2;  // mtlb 2 painter karenge

    cout<<painterpartition(arr,k);
    
}