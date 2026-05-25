#include<bits/stdc++.h>
using namespace std;

int power(int mid,int n,int m){
    long long ans = 1;
    for(int i=1;i<=n;i++){
        ans *= mid;
        if(ans > m) return 2; // overflow ho jayega  left side ma jaate h 
    }
    if(ans == m) return 1;
     return 0; // isme right me jate h
}

int NthRoot(int n,int m){
    int low = 1;
    int high = m;

    while(low<=high){
        int mid = (low+high)/2;
        int check = power(mid,n,m);

        if(check == 1) return mid;
        else if(check == 0) low = mid+1;
        else high = mid-1;

    }
    return -1;
}

int main(){
    int n,m;
    cout<<"enter value of n and m :";
    cin>>n>>m;

    cout<<NthRoot(n,m);
}