// using map 

/*

#include<bits/stdc++.h>
using namespace std;

vector<int> ReplaceEle(vector<int>& arr){
    int n = arr.size();
    vector<int> temp = arr;

    sort(temp.begin() , temp.end());

    map<int,int> mp;

    int rank = 1;

    for(int i=0;i<n;i++){
        if(mp.find(temp[i]) == mp.end()){
            mp[temp[i]] = rank;
            rank++;
        }
    }
     vector<int> ans;

        for(int i=0;i<n;i++){
            ans.push_back(mp[arr[i]]);
        }
        return ans;
}

int main(){
    vector<int> arr = {20,15,26,2,98,6};

    vector<int> ans = ReplaceEle(arr);

    for(int x:ans){
        cout<<x<<" ";
    }
}

*/

// using heap

#include<bits/stdc++.h>
using namespace std;

vector<int> ReplaceELe(vector<int>& arr){
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int n = arr.size();

    for(int x:arr){
        pq.push(x);
    }

    map<int,int> mp;

    int rank = 1;
    while(!pq.empty()){
        int top = pq.top();
        pq.pop();

        if(mp.find(top) == mp.end()){
            mp[top] = rank;
            rank++;
        }
    }
    vector<int> ans;

        for(int i=0;i<n;i++){
            ans.push_back(mp[arr[i]]);
        }

    return ans;
}

int main(){
    vector<int> arr = {20,15,26,2,98,6};

    vector<int> ans = ReplaceELe(arr);

    for(int x:ans){
        cout<<x<<" ";
    }
}
