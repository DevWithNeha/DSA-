#include<bits/stdc++.h>
using namespace std;

int maxProductSubArray(vector<int> &arr){
    int n = arr.size();
    int pre = 1,suff = 1;
    int ans = INT_MIN;

    for(int i=0;i<n;i++){
        if(pre == 0) pre = 1;
        if(suff == 0) suff = 1;

        pre = pre * arr[i];
        suff = suff * arr[n-i-1];

        ans = max(ans,max(pre,suff));
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<maxProductSubArray(arr);
}