#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter number: ";
   cin>>n;
   int dup = n;
    int revnum=0;
    if(n<0){
        cout<<"false";
        return 0;
    }
    while(n>0){
        int ld=n%10;
        n=n/10;
        revnum=(revnum*10)+ld;
    }
    if(dup == revnum) cout<<"true";
    else  cout<<"false";
}