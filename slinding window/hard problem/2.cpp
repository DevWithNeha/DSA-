// brute force

/*
#include<bits/stdc++.h>
using namespace std;
int SubarrayWithKinte(vector<int>& nums,int k){
    int count = 0;

   for(int i=0;i<nums.size();i++){
    unordered_set<char> st;

    for(int j=i;j<nums.size();j++){
        st.insert(nums[j]);

        if(st.size() == k){
            count++;
        } else if(st.size() > k){
            break;
        }
    }
   }
   return count;
}

int main(){
    vector<int> nums = {1,2,1,2,3};
    int k = 2;

    cout<<SubarrayWithKinte(nums,k);
}

*/

//optimal sol

#include<bits/stdc++.h>
using namespace std;
int atmost(vector<int> &nums , int k){
    unordered_map<int,int> mp;
    int left = 0;
    int count = 0;

    for(int right=0;right<nums.size();right++){
        mp[nums[right]]++;

        while(mp.size() > k){
            mp[nums[left]]--;

            if(mp[nums[left]] == 0){
                mp.erase(nums[left]);
            }
            left++;
        }
        count += right-left+1;
    }
    return count;
}
int subarraywithKinte(vector<int>& nums,int k){
   return atmost(nums,k) - atmost(nums,k-1);
}

int main(){
    vector<int> nums = {1,2,1,3,2};
    int k = 2;

    cout<<subarraywithKinte(nums,k);
}