#include<bits/stdc++.h>
using namespace std;

string reverseStr(string s){
    int n = s.size();
    int start = 0;

    for(int end = 0;end<=n;end++){
        if(end==n || s[end]==' '){
            reverse(s.begin()+start,s.begin()+end);

            start = end+1;
        }
    }
    return s;
}

int main(){
    string s;
    cout<<"enter string: ";
    getline(cin,s);

    cout<<reverseStr(s);
}