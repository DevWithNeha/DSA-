#include<bits/stdc++.h>
using namespace std;
void bubblesort(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size()-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    vector<int> arr = {5,3,2,8,6};

    bubblesort(arr);

    for(int x:arr){
        cout<<x<<" ";
    }
}