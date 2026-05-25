#include<bits/stdc++.h>
using namespace std;

vector<int> pse(vector<int> &arr){
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n);

    for(int i=0;i<n;i++){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();

        st.push(arr[i]);
    }
    return ans;
}

int main(){
    vector<int> arr = {4,5,2,10,8};

    vector<int> res = pse(arr);

    for(int x:res){
        cout<<x<<" ";
    }


}