#include<bits/stdc++.h>
using namespace std;

int divide(int dividend,int divisor){
    if(dividend == INT_MIN && divisor == -1){
        return INT_MAX;
    }

    long long n = abs((long)dividend);
    long long d = abs((long)divisor);

    long long ans = 0;

    while(n>=d){
        int cnt = 0;

        while(cnt<31 && n>= (d << (cnt+1))){
            cnt++;
        }
        ans += (1LL<<cnt);
        n -= (d<<cnt);
    }

    if((dividend < 0) ^ (divisor < 0))
    ans = -ans;

    return ans;
}

int main(){
    int dividend,divisor;

    cout<<"enter dividend: ";
    cin>>dividend;

    cout<<" enter divisor: ";
    cin>>divisor;

    if(divisor == 0){
        cout<<"division is not allowed"<<endl;
    }

    cout<<divide(dividend,divisor);
}