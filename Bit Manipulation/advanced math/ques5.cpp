#include<bits/stdc++.h>
using namespace std;
int pow(int x,int n){
    long long nn = n;
    int ans = 1.0;

    if(nn<0){
        x = 1/x;
        nn = -1*nn;
    }

    while(nn>0){
        if(nn % 2==1){
            ans = ans*x;
            nn -= 1;
        } else{
            x = x*x;
            nn /= 2;
        }
    }
    return ans;
}

int main(){
    int x,n;
    cout<<"enter x base and power n: ";
    cin>>x>>n;

    cout<<pow(x,n);
}