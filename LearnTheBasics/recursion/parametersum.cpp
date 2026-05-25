#include<bits/stdc++.h>
using namespace std;

int sum(int i,int s){
  if(i<1){
    return s;
    cout<<sum;
  } 
  return sum(i-1,s+i);
}
int main(){
    int n;
    cout<<"enter number: ";
    cin>>n;    
    cout<<sum(n,0);
}