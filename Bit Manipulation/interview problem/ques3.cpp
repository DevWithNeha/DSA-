#include<bits/stdc++.h>
using namespace std;

void powerset(vector<int> &arr){
    int n = arr.size();

    for(int i = 0;i<(1<<n);i++){
        vector<int> list;

        for(int j=0;j<n;j++){
            if(i&(1<<j)){
            list.push_back(arr[j]);
            }
        }
        cout<<"{";
        for(int x:list) cout<<x<<" ";
        cout<<"}"; 
    }
}

int main(){
    int n;
    vector<int> arr = {1,2,3};

    powerset(arr);
}