#include<bits/stdc++.h>
using namespace std;

bool isSet(int n,int i){
    return(n&(1<<i))!=0; // left shift
}

int main(){
    int n;
    int i;
    cout<<"enter number and its bit :";
    cin>>n>>i;

    if(isSet(n,i)){
        cout<<"bit is set";
    } else{
        cout<<"bit is not set";
    }
}