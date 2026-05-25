#include<bits/stdc++.h>
using namespace std;

vector<int> nextsmallestEle(vector<int> arr){
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n);

    for(int i=n-1;i>=0;i--){
        // pop all ele jo ki bda h current se
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        // ans ko store kro
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();

        // push kro arr ko
        st.push(arr[i]);
    }
    return ans;
}

int main(){
    vector<int> arr = {4,8,5,2,25};

    vector<int> result = nextsmallestEle(arr);

    for(int x:result){
        cout<<x<<" ";
    }
}