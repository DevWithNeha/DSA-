#include<bits/stdc++.h>
using namespace std;

string prefixtopostfix(string s){
    stack<string> st;

    for(int i=s.size()-1;i>=0;i--){
        char c = s[i];

        if(isalnum(c)){
            st.push(string(1,c));
        } else {
            string op1 = st.top();st.pop();
            string op2 = st.top();st.pop();

            string temp = op1+op2+c;

            st.push(temp);
        }
    }
    return st.top();
}

int main(){
    string s;
    cout<<"enter string: ";
    cin>>s;

    cout<<prefixtopostfix(s);
}