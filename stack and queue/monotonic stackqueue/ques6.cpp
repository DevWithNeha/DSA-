#include<bits/stdc++.h>
using namespace std;

// brute force approach

/*
int minSubArray(vector<int> &arr){
    int n = arr.size();
    int sum = 0;

    for(int i=0;i<n;i++){
        int mini = INT_MAX;
        for(int j=i;j<n;j++){
            mini = min(mini,arr[j]);
            sum += mini;
        }
    }
    return sum;
}

*/

int minSubArray(vector<int> &arr){
    int n = arr.size();
    vector<int> pse(n),nse(n);
    stack<int> st;

    // pse

    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        if(st.empty()){
            pse[i] = -1;
        } else{
            pse[i] = st.top();
        }
        st.push(i);
    }

    while(!st.empty()){
        st.pop();
    }

    // nse
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty()) {
            nse[i] = n;
        }
        else {
            nse[i] = st.top();
        }
        st.push(i);
    }

    long long sum = 0;
    int mod = 1e9 + 7;

    for(int i=0;i<n;i++){
        long long left = i - pse[i];
        long long right = nse[i] - i;

        // long long contribution = (arr[i] * left) % mod;
        // contribution = (contribution * right) % mod;

        // sum = (sum + contribution) % mod;

        sum += arr[i] * left * right;
    }
    return sum;
}
int main(){
    vector<int> arr = {3,1,2,4};
    cout<<minSubArray(arr);
}