#include<bits/stdc++.h>
using namespace std;

int CountSubstring(string s){
    int n = s.size();
    return n*(n+1)/2;
}

int main(){
    string s;
    cout<<"enter string: ";
    cin>>s;

    cout<<CountSubstring(s);
}