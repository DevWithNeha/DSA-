#include<bits/stdc++.h>
using namespace std;

// vector<int> nge(vector<int> &arr){
//     vector<int> ans(arr.size(),-1);
//     int n = arr.size();
//     for(int i=0;i<n;i++){
//         for(int j = 1;j<n;j++){
//             int ind = (i+j) % n;
//             if(arr[ind]>arr[i]){
//                 ans[i] = arr[ind];
//                 break;
//             }
//         }
//     }
//     return ans;
// }

vector<int> nge(vector<int> &arr){
    stack<int> st;
    int n = arr.size();
    vector<int> ans(n);

    for(int i=2*n-1;i>=0;i--){
        while(!st.empty() && st.top() <= arr[i%n]){
            st.pop();
        }

        if(i<n){
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
        }
        st.push(arr[i%n]);
    }
    return ans;
}

int main(){
    vector<int> arr ={2,10,12,1,11};

    vector<int> res = nge(arr);

    for(int x:res){
        cout<<x<<" ";
    }
}