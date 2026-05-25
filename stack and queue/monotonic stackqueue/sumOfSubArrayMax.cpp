#include<bits/stdc++.h>
using namespace std;

long long sumSubarrayMax(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    vector<int> nge(n),pge(n);

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

    long long sum = 0;
    for(int i=0;i<n;i++){
        long long left = i-pge[i];
        long long right = nge[i]-i;

        sum += (long long)arr[i] * left * right;
    }
    return sum;
}

int main(){
    vector<int> arr = {3,1,2,4};
    cout<<sumSubarrayMax(arr);
    
}
