#include<bits/stdc++.h>
using namespace std;

int swap(int &a,int &b){
    a = a^b;
    b = a^b;
    a = a^b;
}

int main(){
    int a,b;
    cout<<"enter a and b: ";
    cin>>a>>b;

    swap(a,b);
    cout<<"after swap: "<<"a ="<< a <<"b ="<< b;
}