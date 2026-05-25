#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"enter number: ";
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int i=0;
    int j=n-1;

    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }

    for(int x:arr) cout<<x<<" ";

}