#include<bits/stdc++.h>
using namespace std;

int finddays(vector<int> &arr,int cap){
    int days = 1;
    int loads = 0;

    for(int i=0;i<arr.size();i++){
        if(loads + arr[i] > cap){
            days++;
            loads = arr[i];
        }
        else{
            loads += arr[i];
        }
    } 
    return days;
}

int Shipcapacity(vector<int> &arr,int d){
    int low = *max_element(arr.begin(),arr.end());  // arr ka sbse highest element ko low lenge
    int high = 0; // arr ke sare element ke sum ko high lenge 
    for(int i=0;i<arr.size();i++){
        high +=arr[i];
    }

        while(low<=high){
            int mid = (low+high)/2;

            int days = finddays(arr,mid);

            if(days<=d){
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        return low;
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};

    int d = 5;

    cout<<Shipcapacity(arr,d);
}