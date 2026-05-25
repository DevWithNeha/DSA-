#include<bits/stdc++.h>
using namespace std;

int MininRotSorted(vector<int> &nums){
    int low = 0;
    int high = nums.size()-1;

    while(low<=high){

        if(nums[low]<nums[high]){
            return nums[low];
        }

        int mid = (low+high)/2;

        if(nums[mid]>nums[high]){
            low = mid+1;
        }
        else{
            high = mid;
        }
        return nums[low]; // issi me index return kr denge toh ye pta chl jayega how many time array has been rotated means ques 11
    }

}
int main(){
    vector<int> n = {11,12,13,1,2,3};
    cout<<MininRotSorted(n);
}