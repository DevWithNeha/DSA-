#include<bits/stdc++.h>
using namespace std;

vector<int> prefixsum(vector<int> &arr){
    int n = arr.size();

    vector<int> prefix(n);

    prefix[0] = arr[0];

    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1] + arr[i];
    }
    return prefix;

}

int main(){
    vector<int> arr = {2,4,1,6,7};
    vector<int> res = prefixsum(arr);

    for(int x:res){
        cout<<x<<" ";
    }
}