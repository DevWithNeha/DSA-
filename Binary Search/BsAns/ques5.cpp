#include<bits/stdc++.h>
using namespace std;

int sumByD(vector<int>& arr,int div){
    int sum = 0;
    
    for(int i=0;i<arr.size();i++){
        sum += (arr[i] + div - 1)/div;
    }
    return sum;
}

int smallestDivisor(vector<int> &arr,int limit){
    int low = 1;
    int high =*max_element(arr.begin(),arr.end());

    while(low<=high){
        int mid = (low+high)/2;

        if(sumByD(arr,mid)<=limit){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
}

int main(){
    vector<int> arr = {1,2,5,9};
    int limit = 6;

    int ans = smallestDivisor(arr,limit);
    
    cout<<"SmallestDivisor"<<ans;

}