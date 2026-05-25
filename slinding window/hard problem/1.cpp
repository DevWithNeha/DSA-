// brute force

/*

#include<bits/stdc++.h>
using namespace std;
int longestSubstr(string s,int k){
    int maxlen = 0;

    for(int i=0;i<s.size();i++){

        unordered_set<char> st;

        for(int j=i;j<s.size();j++){
            st.insert(s[j]);

            if(st.size() > k){
             break;
            }
            maxlen = max(maxlen,j-i+1);
        }
    }
    return maxlen;
}

int main(){
    string s;
    cout<<"enter string: ";
    cin>>s;

    int k;
    cin>>k;

    cout<<longestSubstr(s,k);
}

*/



#include<bits/stdc++.h>
using namespace std;

int longestSubstr(string s,int k){

    unordered_map<int,int> mp;
    int maxlen = 0;

    int left = 0;
    for(int right=0;right<s.size();right++){
        mp[s[right]]++;

        if(mp.size() > k){
            mp[s[left]]--;

            if(mp[s[left]] == 0){
                mp.erase(s[left]);
            }
            left++;
        }
        maxlen = max(maxlen,right-left+1);
    }
    return maxlen  ;
}

int main(){
    string s;
    cout<<"enter string: ";
    cin>>s;

    int k;
    cin>>k;

    cout<<longestSubstr(s,k);
}