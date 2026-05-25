#include<bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> arr){
    int ans = 0;
    
    for(int i=0;i<arr.size();i++){
        ans = ans ^ arr[i];
    }
    return ans;
}

int main(){
    vector<int> arr = {2,3,2,4,3};

    cout<<singleNumber(arr);
}