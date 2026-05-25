#include<bits/stdc++.h>
using namespace std;

vector<int> leader(vector<int> &nums){
    int n = nums.size();
    vector<int> t;

    int lead = nums[n-1];
    t.push_back(lead);

    for(int i=n-2;i>=0;i--){
        if(nums[i]>lead){
            lead = nums[i];
            t.push_back(lead);
        }
    }
    reverse(t.begin(),t.end());
    return t;
}
int main(){
    vector<int> nums = {4,5,2,1,3};

    vector<int> ans = leader(nums);

    for(int x:ans) cout<<x<<" ";

}