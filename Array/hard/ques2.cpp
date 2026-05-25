#include<bits/stdc++.h>
using namespace std;
vector<int> majorityEle(vector<int> &arr){
    vector<int> temp;
    int n = arr.size();
    int mini = (int)(n/3)+1;

    unordered_map<int,int> mp;

    for(int i=0;i<n;i++){
        mp[arr[i]]++;
        if(mp[arr[i]]==mini){
            temp.push_back(arr[i]);
        }
        if(temp.size()==2) break;
    }

    sort(temp.begin(),temp.end());
    return temp;
}
int main(){
    vector<int> arr={1,1,1,3,2,2,2};
    vector<int> ans = majorityEle(arr);

    for(int x : ans){
        cout<<x<<" ";
    }
}