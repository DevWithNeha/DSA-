#include<bits/stdc++.h>
using namespace std;

bool isvalid(string s){
    stack<char> st;

    // opening bracket
    for(int i=0;i<s.size();i++){
        char c = s[i];

        if(c == '(' || c=='[' || c=='{'){
        st.push(c);
        } else{
            // closing bracket

            if(st.empty()) return false;

            char top = st.top();
            st.pop();

            if((c==')' && top != '(')||
              (c=='}' && top != '{') ||
              (c==']' && top != '[')){
                    return false;
                }
        }
    }
return st.empty();
}

int main(){
    string s;
    cout<<"enter string: ";
    cin>>s;

    if(isvalid(s)){
        cout<<"balanced parenthesis";
    } else{
        cout<<"invalid parenthesis";
    }
}
