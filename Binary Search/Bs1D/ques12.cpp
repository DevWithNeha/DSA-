#include<bits/stdc++.h>
using namespace std;

int singleEle(vector<int> &nums){
    int n = nums.size();

    if(n==1) return nums[0];

    if(nums[0]!=nums[0+1]) return nums[0];

    if(nums[n-1]!=nums[n-2]) return nums[n-1];

    int low = 1;
    int high = n-2;

    while(low<=high){
        int mid =(low+high)/2;

        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
        return nums[mid];

        // we are in left
        if((mid % 2 == 1 && nums[mid] == nums[mid-1]) || 
        (mid % 2 == 0 && nums[mid] == nums[mid+1])){

        low = mid+1;
        }

        // we are on right
        else{
            high = mid-1;
        }

    }
return -1;
}

int main(){
    vector<int> nums = {1,1,2,2,3,4,4,5,5};
    cout<<singleEle(nums);
    return 0;

}
