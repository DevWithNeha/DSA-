#include<bits/stdc++.h>
using namespace std;

void selectionsort(vector<int>& arr){
    for(int i=0;i<arr.size()-1;i++){
        int minindex = i;

        for(int j=i+1;j<arr.size();j++){
            if(arr[j] < arr[minindex]){
                minindex = j;
            }
            swap(arr[i],arr[minindex]);
        }
    }
}

int main(){
    vector<int> arr = {5,3,2,8,6};

    selectionsort(arr);

    for(int x:arr){
        cout<<x<<" ";
    }

}