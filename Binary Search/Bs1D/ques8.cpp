#include<bits/stdc++.h>
using namespace std;

int search(vector<int> &nums,int k){
    int low = 0;
    int high = nums.size()-1;

    while(low<=high){
        int mid = (low+high)/2;

        if(k == nums[mid])
            return mid;

        if(nums[low]<=nums[mid]){
            if(k>=nums[low] && k<nums[mid]){
                high = mid-1;
            } else low = mid+1;
        }

        else{
            if(k>nums[mid] && k<=nums[high])
                low = mid+1;
            else 
                high = mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {4,5,6,7,0,1,2};
    int k = 0;

    int index = search(nums,k);

    if(index != -1)
        cout<<"element found at index: "<<index<<endl;
    else  
        cout<<"element not found" <<endl;

        return 0;
}