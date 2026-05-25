#include<bits/stdc++.h>
using namespace std;

vector<int> SearchRange(vector<int> &nums,int x){
    int low = 0;
    int high = nums.size()-1;
    int left = -1;
    int right = -1;

    // for first occurrance

   while(low<=high){
    int mid = (low+high)/2;
    if(nums[mid]==x){
        left = mid;
        high = mid-1;
    }
    else if(nums[mid]<x) low = mid+1;
    else high = mid-1;
   }

   // for last occurrance
   
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
   return{left,right};
}

int main(){
    vector<int> nums = {3,4,4,7,8,10};
    int x = 4;
    vector<int> ans = SearchRange(nums,x);
    cout<<"first Ocurrance: "<<ans[0]<<endl;
    cout<<"last Ocurrance: "<<ans[1];
}