#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter a number: ";
    cin>>n;
    int cnt=0;
    while(n>0){
        if(n==0) return 1;
        n=n/10;
        cnt++;
    }
    cout<< cnt;
}