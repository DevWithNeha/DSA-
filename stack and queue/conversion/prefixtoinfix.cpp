#include<bits/stdc++.h>
using namespace std;
string prefixtoinfix(string s){
    stack<string> st;

    for(int i=s.size()-1;i>=0;i--){
        char c = s[i];

        // operand ke liye
        if(isalnum(c)){
            st.push(string(1,c));
        }
        // operator ke liye
        else{
            string op1 = st.top();st.pop();
            string op2 = st.top();st.pop();

            string temp = "("+op1 + c + op2+")";

            st.push(temp);
        }
    }
    return st.top();
}

int main(){
    string s;
    cout<<"enter string: ";
    cin>>s;

    cout<<prefixtoinfix(s);
}