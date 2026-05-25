#include<bits/stdc++.h>
using namespace std;

int main(){
    int start;
    cout<<"enter start number: ";
    cin>>start;

    int goal;
    cout<<"enter goal number: ";
    cin>>goal;

    int n = start^goal;

    int cnt = 0;
    while(n>0){
        n = n&(n-1);
        cnt++;
    }
    cout<<cnt;
}