#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>& arr,int n,int i){
   
    int parent = i;

    while(true){
        int left = 2*parent+1;
        int right = 2*parent+2;

        int largest = parent;

        if(left < n && arr[left] > arr[largest]){
            largest = left;
        }

        if(right < n && arr[right] > arr[largest]){
            largest = right;
        }

        if(largest == parent) break;

        swap(arr[parent],arr[largest]);

        parent = largest;
    }
}
void heapsort(vector<int> &arr){
    int n = arr.size();

    // max heap ke liye
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }

    // size km karne ke liye
    for(int i=n-1;i>0;i--){
        swap(arr[0],arr[i]);

        heapify(arr,i,0);
    }
}

int main(){
    vector<int> arr = {50,45,65,81,2};

    heapsort(arr);

    for(int x:arr){
        cout<<x<<" ";
    }
}