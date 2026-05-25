#include<bits/stdc++.h>
using namespace std;

void num(int i,int n){
    if(i>n) return; // base case
    cout<<i<<" "; // print curent number
    num(i+1,n); //recursive call
}

int main(){
    int n;
    cout<<"enter number: ";
    cin>>n;
    num(1,n);
}