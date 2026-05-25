#include<bits/stdc++.h>
using namespace std;
int cnt=0;
void num(){
    
    if(cnt==4) return;
     cout<<cnt<<endl;
    cnt++;
    num();
}

int main(){
    num();
}