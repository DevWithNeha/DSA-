#include<bits/stdc++.h>
using namespace std;

int binaryToDecimal(int n){
    int result = 0;
    int i=0;

    while(n>0){
        int digit = n%10;
        result += digit*pow(2,i);
        n = n/10;
        i++;
    }
    return result;
}

int main(){
    int n;
    cout<<"enter binary: ";
    cin>>n;

    cout<< binaryToDecimal(n);
}