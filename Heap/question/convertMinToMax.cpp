#include<bits/stdc++.h>
using namespace std;

void MintoMax(vector<int>& arr){
    int n = arr.size();

    for(int i=n/2-1;i >= 0;i--){

        int parent = i;

        while(2*parent+1 < n){
            int left = 2*parent+1;
            int right = 2*parent+2;

            int largest = parent;

            if(left < n && arr[largest] < arr[left]){
                largest = left;
            }

            if(right < n && arr[largest] < arr[right]){
                largest = right;
            }

            if(largest == parent) break;

            swap(arr[parent],arr[largest]);

            parent = largest;
        }
    }
    
}

int main(){
    vector<int> arr = {5,20,30,40,50};

    MintoMax(arr);

    for(int x:arr){
        cout<<x<<" ";
    }
}