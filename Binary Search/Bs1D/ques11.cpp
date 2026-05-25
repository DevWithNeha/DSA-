#include<bits/stdc++.h>
using namespace std;

int findKRotation(vector<int> &nums){
    int low = 0;
    int high = nums.size()-1;
    int ans = INT_MAX;
    int index = 0;

    while(low<=high){

        if(nums[low]<=nums[high]){
            if(nums[low]<ans){
            ans = (ans,nums[low]);
            index = low;
            }
            break;
        }

        int mid = (low+high)/2;

        if(nums[mid]>=nums[low]){  // left part sorted h
            if(nums[low]<ans)
            ans = nums[low];
            index = low;
            low = mid+1;
        }

        else{
            if(nums[mid]<ans){
                ans = nums[mid];
                index = mid;
                high = mid-1;
            }
        }
    }
    return index;
}

int main(){
    vector<int> n = {11,12,13,1,2,3};

    cout<<findKRotation(n);
}