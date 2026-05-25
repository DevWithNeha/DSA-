#include<bits/stdc++.h>
using namespace std;

string longestPalindrome(string s){
    int start = 0 , maxlen = 1;
    int n = s.size();

    for(int i = 0;i<n;i++){

        // odd length ke liye

        int l = i;
        int r = i;
        while(l>=0 && r<n && s[l]==s[r]){
            if(r-l+1>maxlen){
                start = l;
                maxlen = r-l+1;
            }
            l--;r++;
        }

        // even length ke liye

        l=i;
        r=i+1;

        while(l>=0 && r<n  && s[l]==s[r]){
            if(r-l+1>maxlen){
                start = l;
                maxlen = r-l+1;
            }
            l--;r++;
        }
    }
    return s.substr(start,maxlen);
}

int main(){
    string s;
    cout<<"enter string: ";
    cin>>s;

    cout<<longestPalindrome(s);

}