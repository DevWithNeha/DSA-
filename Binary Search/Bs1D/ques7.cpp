#include<bits/stdc++.h>
using namespace std;

int countOcurrance(vector<int> &nums,int x){
    int low = 0;
    int high = nums.size()-1;
    int left = -1;
    int right = -1;

   while(low<=high){
    int mid = (low+high)/2;
    if(nums[mid]==x){
        left = mid;
        high = mid-1;
    }
    else if(nums[mid]<x) low = mid+1;
    else high = mid-1;
   }

   if(left == -1) return 0;
   low = 0;
   high = nums.size()-1;

   while(low<=high){
    int mid = (low+high)/2;

    if(nums[mid]==x){
        right = mid;
        low =mid+1;
    }
    else if(nums[mid]<x) low = mid+1;
    else high = mid-1;
   }
   return right-left+1;
}

int main(){
    vector<int> nums = {3,4,4,7,8,10};
    int x = 4;
    cout<< countOcurrance(nums,x);
    
}