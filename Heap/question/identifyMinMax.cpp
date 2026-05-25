// identify fron array weather its min heap or max heap

#include<bits/stdc++.h>
using namespace std;

bool isMinheap(vector<int>& arr){
    int n = arr.size();

    for(int i=0;i<n/2 - 1;i++){
        int left = 2*i+1;
        int right = 2*1+2;

        if(left<n && arr[left] < arr[i]){
            return false;
        }
        if(right<n && arr[right] < arr[i]){
            return false;
        }
    }
    return true;
}

bool isMaxheap(vector<int>& arr){
    int n = arr.size();

    for(int i=0;i<n/2-1;i++){
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

    vector<int> arr = {10,20,30,40,50};

    if(isMinheap(arr)) {
        cout<< "min Heap";
    }
    else if(isMaxheap(arr)){
        cout<<"max Heap";
    }
    else{
        cout<<"not a heap";
    }

}