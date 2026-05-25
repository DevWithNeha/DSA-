#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter numaber: ";
    cin>>n;

    int count = 0;
    // while(n>0){
    //     n = n & (n-1);
    //     count++;
    // }

    while(n>0){
        if(n%2 == 1) count++;
        n = n/2;
    }
    cout<<count;
}