#include<bits/stdc++.h>
using namespace std;

int subarray(vector<int> &nums,int k){
    unordered_map<int,int> mp;
    mp[0] = 1;

    int prefixsum = 0;
    int count = 0;

    for(int i=0;i<nums.size();i++){
        prefixsum += nums[i];

        if(mp.find(prefixsum-k)!=mp.end()){
            count += mp[prefixsum-k];
        }
        mp[prefixsum]++;
    }
    return count;
}

int main(){

    vector<int> nums = {-2,0,2,-1,0,1};
    int k = 0;

    cout<< subarray(nums,k);

}