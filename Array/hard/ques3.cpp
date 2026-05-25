// // better solution using hashing
// // tc :- O(n2) sc = O(n);

// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>> threeSum(vector<int> &nums){
//     int n = nums.size();
//      set<vector<int>> st;

//      for(int i=0;i<n;i++){
//         set<int> hashset;
//         for(int j =i+1;j<n;j++){

//             int third = -(nums[i]+nums[j]);

//             if(hashset.find(third)!=hashset.end()){
//                 vector<int> temp = {nums[i],nums[j],(int) third};
//                 sort(temp.begin(),temp.end());
//                 st.insert(temp);
//             }
//             hashset.insert(nums[j]);
//         }
//      }
//      return vector<vector<int>> (st.begin(),st.end());
// }

// int main(){
//     vector<int> nums = {-1,0,1,-2,2,0};
    

//     vector<vector<int>> res = threeSum(nums);

//     for(auto triplet:res){
//         for(int x:triplet){
//             cout<<x<<" ";
//         }
//         cout<<endl;
//     }
// }

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums){
    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;

    for(int i=0;i<n;i++){
        if(i>0 && nums[i] == nums[i-1]) continue;

        int j = i+1;
        int k = n-1;
    
    while(j<k){
        int sum = (nums[i]+nums[j]+nums[k]);

        if(sum<0){
            j++;
        }
        else if(sum>0){
            k--;
        }
        else{
            vector<int> temp = {nums[i],nums[j],nums[k]};
            ans.push_back(temp);
            j++;
            k--;
        
        while(j<k && nums[j]==nums[j-1]) j++;
        while(j<k && nums[k]==nums[k+1]) k--;
            }
        }

    }
    return ans;
}

int main(){
       vector<int> nums = {-1,0,1,-2,2,0};
    

        vector<vector<int>> res = threeSum(nums);

        for(auto triplet:res){
            for(int x:triplet){
                cout<<x<<" ";
            }
            cout<<endl;
        }
}