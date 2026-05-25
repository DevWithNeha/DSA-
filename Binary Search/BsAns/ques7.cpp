// linear search

/*
#include<bits/stdc++.h>
using namespace std;

int KthMiss(vector<int> &arr,int k){
    for(int i=0;i<=arr.size();i++){
        if(arr[i] <= k){
            k++;
        }
        else{
            break;
        }
    }
    return k;
}

int main(){
    vector<int> arr = {2,3,4,7,11};
    int k = 5;

    cout<<KthMiss(arr,k);
}
*/

// binary search

#include<bits/stdc++.h>
using namespace std;

int KthMiss(vector<int> &arr,int k){
   int low = 0;
   int high = arr.size()-1;

   while(low<=high){
    int mid = (low+high)/2;

    int missing = arr[mid] - (mid+1);

    if(missing < k){
        low = mid+1;
    }
     else{
        high = mid-1;
     }
   }
   return low+k;  // low + k or high + 1 + k
}

int main(){
    vector<int> arr = {2,3,4,7,11};
    int k = 5;

    cout<<KthMiss(arr,k);
}