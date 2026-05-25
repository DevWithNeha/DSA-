#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &arr){
    int idx = -1;
    int n = arr.size();

    // break point dhundo right se
    for(int i=n-2;i>=0;i++){
        if(arr[i+1]>arr[i]){
            idx = i;
            break;
        }
    }

    // agr last permutation ho ya permutation already maximum ho
    if(idx == -1){
        reverse(arr.begin(),arr.end());
        return;
    }

    // 

    for(int i=n-1;i>idx;i--){
        if(arr[i]>arr[idx]){
            swap(arr[i],arr[idx]);
            break;
        }
    }
    reverse(arr.begin()+idx+1,arr.end());
}

int main(){
    vector<int> arr = {5,4,3,1,2};

    nextPermutation(arr);

    for(int x:arr) cout<<x<<" ";
    
}