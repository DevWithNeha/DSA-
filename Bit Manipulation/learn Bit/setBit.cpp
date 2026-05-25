#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int i;
    cout<<"enter number and bit position: ";
    cin>>n>>i;

    int result = n|(1<<i);

    cout<<result;
}