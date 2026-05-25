
// brute force

/*
#include<bits/stdc++.h>
using namespace std;

int binarySubArrSum(vector<int>& nums,int goal){
    int count = 0;

    for(int i=0;i<nums.size();i++){
        int sum = 0;
        for(int j=i;j<nums.size();j++){
            sum += nums[j];

            if(sum == goal) count++;
        }
    }
    return count;
}

int main(){
    vector<int> nums = {1,1,0,1,0,0,1};
    int goal = 3;

    cout<<binarySubArrSum(nums,goal);

}

*/

// optimal sol

#include<bits/stdc++.h>
using namespace std;

int atmost(vector<int> &nums , int goal){
    if(goal < 0)return 0;

    int left = 0;
    int sum = 0;
    int count = 0;

    for(int right=0;right<nums.size();right++){
        sum += nums[right];

        while(sum>goal){
            sum -= nums[left];
            left++;
        }
        count += (right-left+1);
    }
    return count;
}

int numSubarrayWithSum(vector<int>& nums,int goal){
    return atmost(nums,goal) - atmost(nums,goal-1);
}

int main(){
    vector<int> nums = {1,0,1,0,1};

    int goal = 2;

    cout<<numSubarrayWithSum(nums,goal);
}