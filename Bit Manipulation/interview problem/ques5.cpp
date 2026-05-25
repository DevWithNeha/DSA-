#include<bits/stdc++.h>
using namespace std;

// vector<int> singleNumber(vector<int> arr){
//     unordered_map<int,int> mp;

//     for(int i=0;i<arr.size();i++){
//         mp[arr[i]]++;
//     }
//     vector<int> ans;

//     for(auto it:mp){
//         if(it.second==1){
//             ans.push_back(it.first);
//         }
//     }
//     return ans;
// }

vector<int> singleNumber(vector<int> &arr){
    int xorR = 0;

    for(int i=0;i<arr.size();i++){
        xorR ^= arr[i];
    }
    int rightmost = (xorR & (-xorR));

    int b1 = 0,b2 = 0;

    for(int x:arr){
        if(x & rightmost){
            b1 ^= x;
        } else{
            b2 ^= x;
        }
    }
    return {b1,b2};
}

int main(){
    vector<int> arr = {1,2,1,3,2,5};

    vector<int> res = singleNumber(arr);

    for(int x:res){
        cout<<x<<" ";
    }
}