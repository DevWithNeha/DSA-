#include<bits/stdc++.h>
using namespace std;

string postfixtoprefix(string s){
    stack<string> st;

    for(int i=0;i<s.size();i++){
        char c = s[i];

        //operand stack me push kr rhe
        if(isalnum(c)){
            st.push(string(1,c));
        } else {
            string op2 = st.top();st.pop();
            string op1 = st.top();st.pop();

            string temp = c + op1 + op2;

            st.push(temp);
        }
    }
    return st.top();
}

int main(){
    string s;
    cout<<" enter string: ";
    cin>>s;

    cout<<postfixtoprefix(s);

}