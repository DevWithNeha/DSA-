#include<bits/stdc++.h>
using namespace std;
string largestoddNumber(string s){

    for(int i = s.size();i>=0;i--) {
        if((s[i]-'0') % 2 == 1) 
        return s.substr(0,i+1);
    }
    return "";
}

int main(){
    string s;
    cin>>s;

    cout<<largestoddNumber(s);

}