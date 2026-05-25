#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &arr){
    int n = arr.size();
    if(n == 0) return 0;

    unordered_set<int> st;

    for(int x:arr){
        st.insert(x);
    }

    int longest = 0;

    for(auto x:st){
        if(st.find(x-1)==st.end()){
           int cnt = 1;
           int curr = x;
        

        while(st.find(curr+1)!=st.end()){
            cnt++;
            curr++;
        }
        longest = max(longest,cnt);
        }
    }
    return longest;
}

int main(){
    vector<int> arr = {100,4,200,1,3,2};
    cout<< longestConsecutive(arr);
}