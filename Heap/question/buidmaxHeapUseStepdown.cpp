#include<bits/stdc++.h>
using namespace std;
void buildMaxHeap(vector<int>& arr){
    int n = arr.size();
   

    for(int i=n/2-1;i>=0;i--){

        int  parent = i;

        while(true){

            int left = 2*parent+1;
            int right = 2*parent+2;
            
            int largest = parent;

            if(left<n && arr[left] > arr[parent]){
                largest = left;
            }
            if(right<n && arr[right] > arr[parent]){
                largest = right;
            }

            if(largest == parent) break;

            swap(arr[largest],arr[parent]);

            parent = largest;
        }
    }

}

int main(){
    vector<int> arr = {14,15,12,22,17,20,18,24,23,30,19};

    buildMaxHeap(arr);

    for(int x:arr){
        cout<<x<<" ";
    }
}