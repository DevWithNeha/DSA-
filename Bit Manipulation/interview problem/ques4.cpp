#include<bits/stdc++.h>
using namespace std;

int XORupto(int n){
    if(n % 4 == 0) return n;
    if(n % 4 == 1) return 1;
    if(n % 4 == 2) return n+1;
    else return 0;
}
int rangeXOR(int l,int r){
return XORupto(r) ^ XORupto(l-1);
}


int main(){
    int l,r;
    cout<<"enter L and R: ";
    cin>>l>>r;

    cout<<rangeXOR(l,r);
}