#include<bits/stdc++.h>
using namespace std;

void num(int i,int n){
    if(i<1) return; // base case
    cout<<i<<" "; // print curr  ent number
    num(i-1,n); //recursive call
}

int main(){
    int n;
    cout<<"enter number: ";
    cin>>n;
    num(n,n);
}