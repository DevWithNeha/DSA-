// brute force

/*
#include<bits/stdc++.h>
using namespace std;

int NiceSubarray(vector<int>& nums,int k){
    int count = 0;

    for(int i=0;i<nums.size();i++){
        int odd = 0;
        for(int j=i;j<nums.size();j++){
            if(nums[j]%2==1) odd++;

            if(odd == k) count++;
        }
    }
    return count;
}

int main(){
    vector<int> nums = {1,1,2,1,1} ;
    int k = 3;

    cout<<NiceSubarray(nums,k);

}

*/

// optimal sol

#include<bits/stdc++.h>
using namespace std;
int atmost(vector<int>& nums , int k){
    if(k < 0) return 0;

    int left = 0 , odd = 0 , count = 0;

    for(int right=0;right<nums.size();right++){
        if(nums[right] % 2 == 1) odd++;

        while(odd > k){
            if(nums[left] % 2 == 1) odd--;
            left++;
        }
        count += right - left + 1;
    }
    return count;
}
int NiceSubarray(vector<int>& nums,int k){
    return atmost(nums,k) - atmost(nums,k-1);
}

int main(){
    vector<int> nums = {1,1,0,1,1};
    int k = 3;

    cout<<NiceSubarray(nums,k);
}