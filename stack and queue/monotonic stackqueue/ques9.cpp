#include<bits/stdc++.h>
using namespace std;
string removeK(string nums , int k){
    int n = nums.size();
    stack<char> st;


    // agar previous bda h next se toh previous ko pop kr do
    for(char c:nums){
        while(!st.empty() && k>0 && st.top() > c){
            st.pop();
            k--;
        }
        st.push(c);
    }

        // agar sorted ho aur k bacha h toh right side ko pop kr do
        while(!st.empty() && k>0){
            st.pop();
            k--;
        }

        // string bna ke usme sbke push kr do
        string ans ="";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        // leading 0 htao jaise 0020 ho toh 20 hi bache
        int i=0;
        while(i<ans.size() && ans[i] == '0') i++;
        ans = ans.substr(i);

        // agr ans empty ho tb
        if(ans == "") return 0;
        return ans;
    }


int main(){
    string s ;
    cout<<"enter strings: ";
    cin>>s;

    int k;
    cout<<"enter k: ";
    cin>>k;

    cout<<removeK(s,k);
}