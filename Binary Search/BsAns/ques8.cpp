// linear search

/*
#include<bits/stdc++.h>
using namespace std;

bool cowplace(vector<int> &arr,int cows,int dist){
    int cntcows = 1;
    int last = arr[0];

    for(int i=1;i<arr.size();i++){
        if(arr[i]-last >= dist){
            cntcows++;
            last = arr[i];
        }
        if(cntcows>=cows){
            return true;
        }
    }
    return false;
}
int AggressiveCow(vector<int> &arr,int n,int k){
    sort(arr.begin(),arr.end());

    int limit = arr.back()-arr[0];
    int ans = 0;
    for(int dist=1;dist<n;dist++){
        if(cowplace(arr,k,dist)){
            ans = dist;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {0,3,4,7,10,9};
    int n = 6;
    int k = 4;

    cout<<AggressiveCow(arr,n,k);
}

*/

// binary search

#include<bits/stdc++.h>
using namespace std;

bool canCowPlace(vector<int> &stalls,int k,int dist){
    int cntcow = 1;
    int last = stalls[0];

    for(int i = 0;i < stalls.size();i++){
        if(stalls[i] - last >= dist){
            cntcow++;
            last = stalls[i];
        }
        if(cntcow>=k){
            return true;
        }
    }
    return false;
}

int AggressiveCows(vector<int> &stalls,int k){
    int low = 1;
    int high = stalls.back()-stalls[0];
    int ans = 0;

    while(low<=high){
        int mid = (low+high)/2;

        if(canCowPlace(stalls,k,mid)==true){
            ans = mid;
            low = mid+1;
        }
        else{
            high= mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> stalls = {0,3,4,7,9,10};
    int k = 4;

    cout<<AggressiveCows(stalls,k);
}