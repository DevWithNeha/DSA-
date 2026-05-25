#include<bits/stdc++.h>
using namespace std;

// vector<int> nge(vector<int> &arr){
//     vector<int> ans(arr.size(),-1);
//     for(int i=0;i<arr.size();i++){
//         for(int j = i+1;j<arr.size();j++){
//             if(arr[j]>arr[i]){
//                 ans[i] = arr[j];
//                 break;
//             }
//         }
//     }
//     return ans;
// }

vector<int> nge(vector<int> arr){
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }

        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();

        st.push(arr[i]);
    }
    return ans;
}
int main(){
    vector<int> arr = {6,0,3,8,9,2};

    vector<int> res = nge(arr);

   for(int x:res){
    cout<< x <<" ";
   }
}