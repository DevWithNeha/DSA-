#include<bits/stdc++.h>
using namespace std;

int precendence(char c){
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return -1; 
}

string infinixToPostfix(string s){
    stack<char> st;
    string ans = " ";

    for(int i=0;i<s.size();i++){
        char c = s[i];

        if((c >= 'A' && c <= 'Z')||
          (c >= 'a' && c <='z')||
          (c >= '0' && c <= '9')){
            ans += c;
          }
        
          // opening bracket

        else if(c == '('){
            st.push(c);
        }

        // closing bracket
        else if(c == ')'){
            while(!st.empty() && st.top()!='('){
                ans += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }

        // operator
        else{
            while(!st.empty() && precendence(st.top()) >= precendence(c)){
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
    return ans;
}

int main(){
    string s;
    cout<<"enter string: ";
    cin>>s;

    cout<<infinixToPostfix(s);

}