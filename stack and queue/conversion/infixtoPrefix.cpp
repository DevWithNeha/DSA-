#include<bits/stdc++.h>
using namespace std;

int precendence(char c){
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return -1;
}

string infixtoPrefix(string s){
    string str = s;
    // pehle reverse kro
    reverse(str.begin(),str.end());

    // swap bracket
    for(int i=0;i<str.size();i++){
        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] = '(';
        }

        stack<char> st;
        string ans = "";

        // infix to postfix

        for(int i=0;i<str.size();i++){
            char c = str[i];

        if((c >= 'A' && c <= 'Z')||
           (c >= 'a' && c <= 'z')||
           (c >= '0' && c <= '9')){
            ans += c;
           }

           else if(c == '('){
            st.push(c);
           }

           else if(c == ')'){
            while(!st.empty() && st.top()!='('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        } 
           
           else{
            while(!st.empty() && precendence(st.top()) > precendence(c)){
                ans += st.top();
                st.pop();
            }
            st.push(c);
           }
        }

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
    


int main(){
    string s;
    cout<<"enter string: ";
    cin>>s;

    cout<<infixtoPrefix(s);
}