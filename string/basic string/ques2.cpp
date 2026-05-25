#include<bits/stdc++.h>
using namespace std;

void reverseRange(string &s,int start,int end){
    while(start<end){
        swap(s[start],s[end]);
        start++;
        end--;
    }
}
string reverseStrs(string s){
    int n = s.size();
    string temp = "";
    int i = 0;

    while(i<n){

        // skip spaces
        while(i<n && s[i] == ' ') i++;

        // take word
        while(i<n && s[i]!=' '){
            temp += s[i];
            i++;
        }

        // skip spaces
        while(i<n && s[i] == ' ')i++;

        //add single spaces
        if(i<n) temp += ' ';
    }

    // reverse whole string
    reverse(temp.begin(),temp.end());

    int start = 0;
    for(int i=0;i<=temp.size();i++){
        if(i == temp.size()  || temp[i] == ' '){

            reverseRange(temp,start,i-1);
            start = i+1;
        
        }
    }
    return temp;
}


int main(){
    string s = "hello neha";

    cout<<reverseStrs(s);
}