#include<bits/stdc++.h>
using namespace std;
int heapHeight(vector<int>& arr){
    int n = arr.size();

    if(n == 1) return 1;

    int height = 0;

    while(n>1){
        n = n/2;
        height++;
    }
    return height;
}

int main(){
    vector<int> arr = {1,3,5,9,8};

    cout<<heapHeight(arr);
}