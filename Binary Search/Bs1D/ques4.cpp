#include<bits/stdc++.h>
using namespace std;
int SearchInsertPos(vector<int> &nums,int x){
    int low = 0;
    int high = nums.size();

    while(low<=high){
        int mid = (low+high)/2;

        if(nums[mid]==x) return mid;

        else if(nums[mid]<x) low = mid+1;
        else high = mid-1;
    }
    return low;
}
int main(){
    vector<int> nums = {1,3,5,6};
    int x = 2;

    cout<<SearchInsertPos(nums,x);

}