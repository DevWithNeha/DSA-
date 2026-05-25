#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter number: ";
    cin>>n;

    int i;
    cout<<"enter ith position: ";
    cin>>i;

    int result = n&~(1<<i);

    cout<<result;
}