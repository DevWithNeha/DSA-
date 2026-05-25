#include<bits/stdc++.h>
using namespace std;
string minWindowSubstr(string s,string t){
    int hash[256] = {0};

    // t ke sare charachter ko map me daal diye 
    for(char c:t){
        hash[c]++;
    }

    int l=0,r=0;
    int minlen = INT_MAX;
    int startindex = -1;
    int cnt = 0;

    int n = s.size();
    int m = t.size();

    // r move karenge
    while(r<n){
        if(hash[s[r]] > 0){
            cnt++;
        }
        hash[s[r]]--;

        // shrink start
        while(cnt == m){
            if(r-l+1 < minlen){
                minlen = r-l+1;
                startindex = l;
            }

            hash[s[l]]++;

            if(hash[s[l]] > 0){
                cnt--;
            }
            l++;
        }
        r++;
    }
    if(startindex == -1) return " ";
    return s.substr(startindex,minlen);
}

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout<<minWindowSubstr(s,t);
}