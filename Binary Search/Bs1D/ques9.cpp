#include<bits/stdc++.h>
using namespace std;

bool searchArray(vector<int> &nums,int k){
    int low = 0;
    int high = nums.size()-1;

    while(low<=high){
        int mid = (low+high)/2;

        if(nums[mid]==k)
            return mid;

            // duplicate case
        if(nums[low]==nums[mid] && nums[mid]==nums[high]){
            low++;
            high--;
            continue;
        }

        if(nums[low]<=nums[mid]){
        if(nums[low]<=k && k<nums[mid]){
            high = mid-1;
        } else low = mid+1;
    } else{
        if(nums[mid]<k && k<=nums[high]){
            low = mid+1;
        } else high = mid-1;
    }
    }
    return false;
}
int main(){
    vector<int> nums = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int k = 3;

    int index = searchArray(nums,k);

    if(searchArray(nums,k))
        cout<<"element found"<<index<<endl;
    else  
        cout<<"element not found" <<endl;

        return 0;
}

