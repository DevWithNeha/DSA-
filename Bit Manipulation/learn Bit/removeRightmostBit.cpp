#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter number: ";
    cin>>n;

    int result = n & (n-1);

    cout<<result;
}