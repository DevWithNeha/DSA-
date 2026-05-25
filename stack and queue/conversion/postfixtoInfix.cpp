#include<bits/stdc++.h>
using namespace std;
string postfixtoinfix(string s){
    stack<string> st;

    for(int i=0;i<s.size();i++){
        char c = s[i];

        // operand ke liye
        if((c >= 'A' && c <= 'Z')||
           (c >= 'a' && c <= 'z')||
           (c >= '0' && c <= '9')){
                st.push(string(1,c));
            }

            // operator ke liye
            else{
                string t2 = st.top();st.pop();
                string t1 = st.top();st.pop();

                string temp = t1 + c + t2;
                st.push(temp);
            }
    }
    return st.top();
}

int main(){
    string s;
    cout<<"enter string: ";
    cin>>s;

    cout<<postfixtoinfix(s);
}