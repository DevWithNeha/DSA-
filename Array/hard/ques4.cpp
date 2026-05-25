// brute solution

// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<int>> fourSum(vector<int> &nums,int target){
//     int n = nums.size();

//     set<vector<int>> st;

//     for(int i = 0;i<n;i++){
//         for(int j=i+1;j<n;j++){
//             for(int k=j+1;k<n;k++){
//                 for(int l=k+1;l<n;l++){

//                     long long sum = nums[i]+nums[j];
//                     sum +=nums[k]+nums[l];
//                     if(sum == target){
//                         vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};

//                         sort(temp.begin(),temp.end());

//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//     }
//     //convert set to vector
//     vector<vector<int>> ans(st.begin(),st.end());
//     return ans;
// }

// int main(){
//     vector<int> nums = {1,0,-1,0,-2,0};
//     int target = 0;

//     vector<vector<int>> res = fourSum(nums,target);

//     for(auto quad : res){
//         for(int x:quad){
//             cout<<x<<" ";
//         }
//         cout<<endl;
//     }


// }

// better solution

// #include<bits/stdc++.h>
// using namespace std;

// vector<vector<int>> fourSum(vector<int> &nums,int target){
//     int n = nums.size();

//     set<vector<int>> st;

    
//     for(int i=0;i<n;i++){
//         for(int j = i+1;j<n;j++){

//             set<long long> hashset;

//             for(int k = j+1;k<n;k++){

//                 long long sum = nums[i]+nums[j]+nums[k];
//                 long long need = target - sum;

//                 if(hashset.find(need)!=hashset.end()){
//                     vector<int> temp = {nums[i],nums[j],nums[k],(int) need};
                

//                 sort(temp.begin(),temp.end());
//                 st.insert(temp);
//                 }
//                 hashset.insert(nums[k]);

//             }
            
//         }
//     }

//     return vector<vector<int>>(st.begin(),st.end());
// }

// int main(){
//     vector<int> nums = {1,0,-1,0,-2,0};
//         int target = 0;

//         vector<vector<int>> res = fourSum(nums,target);

//         for(auto quad : res){
//             for(int x:quad){
//                 cout<<x<<" ";
//             }
//             cout<<endl;
//         }
// }

// using two pointer

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums,int target){
    vector<vector<int>> ans;

    sort(nums.begin(),nums.end());

    int n = nums.size();

    for(int i=0;i<n;i++){
        if(i>0 && nums[i] == nums[i-1]) continue;

        for(int j=i+1;j<n;j++){
            if(j>i+1 && nums[j] == nums[j-1]) continue;

                int k = j+1;
                int l = n-1;

                while(k<l){
                    long long sum = nums[i]+nums[j]+nums[k]+nums[l];

                    if(sum == target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;

                        while(k<l && nums[k]==nums[k-1]) k++;

                        while(k<l && nums[l]==nums[l+1]) l--;
                    }
                    else if(sum<target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }  
                
            }
        }
        return ans;
}

int main(){
    vector<int> nums = {1,0,-1,0,-2,0};
        int target = 0;

        vector<vector<int>> res = fourSum(nums,target);

        for(auto quad : res){
            for(int x:quad){
                cout<<x<<" ";
            }
            cout<<endl;
        }
}

