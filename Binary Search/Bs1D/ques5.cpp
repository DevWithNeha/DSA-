#include<bits/stdc++.h>
using namespace std;

vector<int> floorandCeil(vector<int> &nums,int x){
    int low = 0;
    int high = nums.size()-1;
    int floor = -1;
    int ceil = -1;

    while(low<=high){
        int mid = (low+high)/2;

        if(nums[mid]==x){
            floor = nums[mid];
            ceil = nums[mid];
            break;
        }

        else if(nums[mid]<x){
            floor = nums[mid];
            low = mid+1;
        } else {
            ceil = nums[mid];
            high = mid-1;
        }
    
    }
    return{floor,ceil};
}

int main(){
    vector<int> nums = {3,4,4,7,8,10};
    int x = 5;
    vector<int> ans = floorandCeil(nums,x);
    cout<<"floor "<<ans[0]<<endl;
    cout<<"ceil "<<ans[1];
}