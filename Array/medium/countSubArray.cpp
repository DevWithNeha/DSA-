// brute solution

// #include<bits/stdc++.h>
// using namespace std;

// int countSubarray(vector<int> &arr,int k){
//     int n = arr.size();
//     int count = 0;
//     for(int i=0;i<n;i++){
//         int sum = 0;
//         for(int j= i;j<n;j++){
//             sum +=arr[j];
//             if(sum == k){
//                 count++;
//             }
//         }
//     }
//     return count;
// }
// int main(){
//     vector<int> arr = {1,2,3,1,1,1};
//     int k = 3;
//     cout<<countSubarray(arr,k);
// }

// optimal solution

#include<bits/stdc++.h>
using namespace std;

int countSubarray(vector<int> &arr,int k){
    unordered_map<int,int> mp;
    mp[0] = 1;
    int prefixsum = 0;
    int count = 0;

    for(int i=0;i<arr.size();i++){
        prefixsum +=arr[i];

    if(mp.find(prefixsum-k)!=mp.end()){
        count += mp[prefixsum-k];
    }
    mp[prefixsum]++;
    }

    return count;
}
int main(){
    vector<int> arr = {1,2,3,1,1,1};

    int k = 3;
    cout<<countSubarray(arr,k);
}