#include<bits/stdc++.h>
using namespace std;

bool ismaxheap(vector<int>& arr){
    int n = arr.size();

    for(int i = 0;i<n;i++){
        int left = 2*i+1;
        int right = 2*i+2;

        if(left<n && arr[i] < arr[left]){
            return false;
        }

        if(right<n && arr[i] < arr[right]){
            return false;
        }
    }
    return true;
}

int main(){
    vector<int> arr = {80,60,70,40,30};

    if(ismaxheap(arr)){
        cout<<"yes";
    } else{
        cout<<"no";
    }
}