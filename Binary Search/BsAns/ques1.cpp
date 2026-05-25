#include<bits/stdc++.h>
using namespace std;

int floorsqrt(int n){
    int low = 1;
    int high = n;

    while(low<=high){
        long long mid = (low+high)/2;
        long long val = (mid*mid);

        if(val == n){
            return mid;
        }
        else if(val < n){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return high;
}

int main(){
    int n;
    cout<<"enter number :";
    cin>>n;

    cout<<floorsqrt(n);
    
}