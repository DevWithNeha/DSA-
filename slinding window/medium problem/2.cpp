// brute force 

/*
#include<bits/stdc++.h>
using namespace std;
int flipmaxone(vector<int> &arr , int k){
    int maxlen = 0;
    for(int i=0;i<arr.size();i++){
        int zerocount = 0;
        for(int j=i;j<arr.size();j++){
            if(arr[j] == 0) zerocount++;

            if(zerocount > k) break;

            maxlen = max(maxlen,j-i+1);
        }
    }
    return maxlen;
}

int main(){
    vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
    int k=2;

    cout<<flipmaxone(arr,k);
}

*/

// optimal solution

#include<bits/stdc++.h>
using namespace std;
int flipmaxone(vector<int> &arr , int k){
    int l = 0;
    int maxlen = 0;
    int zerocount = 0;

    for(int r=0;r<arr.size();r++){
        if(arr[r] == 0) zerocount++;

        if(zerocount > k){
            if(arr[l] == 0) zerocount--;
            l++;

            maxlen = max(maxlen,r-l+1);
        }
    }
    return maxlen;
}

int main(){
    vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 3;
    cout<<flipmaxone(arr,k);
}