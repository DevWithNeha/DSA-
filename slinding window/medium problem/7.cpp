#include<bits/stdc++.h>
using namespace std;
int AllcharchterOccurrance(string s){

    int count = 0;
    
    for(int i=0;i<s.size();i++){
        set<char> st;

        for(int j=i;j<s.size();j++){
            st.insert(s[j]);

            if(st.size() == 3) count++;
        }
    }
    return count;
}

int main(){
    string s;
    cout<<"enter string: ";
    cin>>s;

    cout<<AllcharchterOccurrance(s);
}