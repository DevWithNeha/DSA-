#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1,1,0,1,0,1,1,0};

    int n = arr.size();

    int count = 0;
    int maxcount = 0;

    for(int i=0;i<n;i++){
        if(arr[i]==1)
        {
            count++;
            maxcount = max(count,maxcount);
        }
        else{
            count = 0;
        }
    }
    cout<<maxcount;
}