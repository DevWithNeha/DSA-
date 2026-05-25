#include<bits/stdc++.h>
using namespace std;

int subArraywithXorK(vector<int> &arr , int k){
    unordered_map<int,int> mp;
    int xr = 0;
    int cnt = 0;

    mp[0] = 1;

    for(int i=0;i<arr.size();i++){
        xr = xr^arr[i];
        int x = xr^k;

        if(mp.find(x)!=mp.end()){
            cnt += mp[x];
        }
        
        mp[xr]++;

    }
    return cnt;
}


int main(){
    vector<int> arr = {-2,0,2,-1,0,1};
    int k = 0;
    cout<<subArraywithXorK(arr,k);
}