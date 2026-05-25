// brute force

/*
#include<bits/stdc++.h>
using namespace std;
int longestSubstr(string s){
    int n = s.size();
    int maxlen = 0;

    for(int i=0;i<n;i++){
        unordered_set<char> st;

        for(int j=i;j<n;j++){
            if(st.find(s[j])!=st.end()){
                break;
            }
            st.insert(s[j]);
            maxlen = max(maxlen,j-i+1);
        }
    }
    return maxlen;
}

int main(){
    string s;
    cout<<"enter string:";
    cin>>s;

    cout<<longestSubstr(s);
}

*/

// optimal solution

#include<bits/stdc++.h>
using namespace std;

int longestSubstr(string s){
    vector<int> hash(256,-1);

    int l=0;
    int maxlen= 0;

    for(int r=0;r<s.size();r++){
        if(hash[s[r]] >= l){
            l = hash[s[r]]+1;
        }
        hash[s[r]] = r;

        maxlen = max(maxlen,r-l+1);
    }
    return maxlen;
}

int main(){
    string s;
    cout<<"enter string: ";
    cin>>s;

    cout<<longestSubstr(s);
}