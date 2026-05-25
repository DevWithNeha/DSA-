#include<bits/stdc++.h>
using namespace std;

int rangeSubarray(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    vector<int> nge(n),pge(n);
    vector<int> nse(n),pse(n);

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

    long long minsum = 0;
    int mod = 1e9 + 7;

    for(int i=0;i<n;i++){
        long long left = i - pse[i];
        long long right = nse[i] - i;

        long long contribution = (arr[i] * left) % mod;
        contribution = (contribution * right) % mod;

        minsum = (minsum + contribution) % mod;  
    }

    while(!st.empty()){
        st.pop();
    }
    
     // pge
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()]<arr[i]){
            st.pop();
        }

        if(st.empty()) pge[i] = -1;
        else pge[i] = st.top();

        st.push(i);
    }
    while(!st.empty()){
        st.pop();
    }

    // nge

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }

        if(st.empty()) nge[i] = n;
        else nge[i] = st.top();

        st.push(i);
    }

    long long maxsum = 0;
    for(int i=0;i<n;i++){
        long long left = i-pge[i];
        long long right = nge[i]-i;

        maxsum += (long long)arr[i] * left * right;
    }

    return maxsum-minsum;

}

int main(){
    vector<int> arr = {3,1,2,4};
    cout<<rangeSubarray(arr);
}