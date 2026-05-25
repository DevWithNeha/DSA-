#include<bits/stdc++.h>
using namespace std;

int maximumDepth(string s){
    int currentDepth = 0;
    int maxDepth = 0;

    for(char ch:s){
        if(ch == '('){
            currentDepth++;
            maxDepth = max(currentDepth,maxDepth);
        }
        else if(ch == ')') {
            currentDepth--;
        }
    }
    return maxDepth;
}

int main(){
    string s;
    cout<<"enter string: ";
    cin>>s;

    cout<<maximumDepth(s);

}