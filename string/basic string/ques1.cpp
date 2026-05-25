// using stack

/*
#include<bits/stdc++.h>
using namespace std;

string removeOuter(string s){
    string ans = "";
    stack<char> st;

    for(char ch:s){  // s ke hr ch ko ik ik kr ke traverse kro
        if(ch == ')') st.pop();

        if(!st.empty()) ans+=ch;

        if(ch=='(') st.push(ch);
    }

    return ans;

}

int main(){
    string s;
    cin>>s;

    cout<<removeOuter(s)<<endl;

    return 0;
}

*/

#include<bits/stdc++.h>
using namespace std;

string removeOuter(string s){
    string ans = "";

    int cnt = 0;

    for(char ch:s){
        if(ch==')') cnt--;

        if(cnt>0) ans += ch;

        if(ch=='(') cnt++;
    }
    return ans;
}

int main(){
    string s;
    cin>>s;

    cout<<removeOuter(s)<<endl;
}