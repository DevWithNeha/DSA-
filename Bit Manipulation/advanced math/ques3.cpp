#include<bits/stdc++.h>
using namespace std;

int countprime(int l,int r){
    if(r<2) return 0;

    vector<bool> prime(r+1,true);
    prime[0] = prime[1] = false;

    for(int i=2;i*i<r;i++){
        if(prime[i]!=true) continue;

        for(int j = i*i;j<=r;j+=i){
            prime[j] = false;
        }
    }
    int cnt = 0;
    for(int i=max(l,2);i<=r;i++){
        if(prime[i] == true) cnt++;
    }
    return cnt;
}

int main(){
    int l,r;
    cout<<"enter numbers: ";
    cin>>l>>r;

    cout<<countprime(l,r);
}