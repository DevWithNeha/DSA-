#include<bits/stdc++.h>
using namespace std;

/*
vector<int> slindingWindowMax(vector<int> &arr , int k){
    int n = arr.size();
    vector<int> ans;

    for(int i = 0;i<n-k;i++){
        int maxi = arr[i];

        for(int j = i;j<i+k;j++){
            maxi = max(maxi,arr[j]);
        }
        ans.push_back(maxi);
    }
    return ans;
}
*/

vector<int> slindingWindowMax(vector<int> &arr , int k){
    deque<int> dq;
    vector<int> ans;

    // emove out of window
    for(int i=0;i<arr.size();i++){
        if(!dq.empty() && dq.front() == i-k){
            dq.pop_front();
        }

        // remove smaller ele
        while(!dq.empty() && dq.front() < arr[i]){
            dq.pop_front();
        }

        // ele push

        dq.push_back(i);

        if(i >= k-1){
            ans.push_back(arr[dq.front()]);
        }
    }
    return ans;
}
int main(){
    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    vector<int> res = slindingWindowMax(arr , k);

    for(int x:res){
        cout<<x<<" ";
    }
}