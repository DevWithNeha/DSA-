#include<bits/stdc++.h>
using namespace std;
bool isomorphic(string s,string t){
    if(s.size() != t.size()) return false;

    unordered_map<char,char> m1,m2;

    for(int i=0;i<s.size();i++){
        char c1 = s[i];
        char c2 = t[i];

        // s->t check

        if(m1.count(c1)){
            if(m1[c1] != c2) return false;
        }else{
            m1[c1] = c2;
        }

        // t->s check

        if(m2.count(c2)){
            if(m2[c2] != c1) return false;
        }else{
            m2[c2] = c1;
        }
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    string t;
    cin>>t;

    if(isomorphic(s,t)) cout<<"yes";
    else cout<<"no";
}