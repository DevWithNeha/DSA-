// #include<bits/stdc++.h>
// using namespace std;
// int longestsubarray(vector<int> &arr,int k){
//     int n = arr.size();
//     int maxlen = 0;
//     for(int i=0;i<n;i++){
//         int sum = 0;
//         for(int j = i;j<n;j++){
//             sum += arr[j];
//             if(sum==k){
//                 maxlen = max(maxlen,j-i+1);
//             }
//         }
//     }
//     return maxlen;
// }

// int main(){
//     vector<int> arr = {10,5,2,7,1,9};
//     int k =15;
//     cout<<longestsubarray(arr,k);
// }

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int left = 0,right = 0;
    int maxlen = 0;
    int sum = 0;

    while(right<n){
        sum += arr[right];

        while(sum>k){
            sum -= arr[left];
            left++;
        }

        if(sum == k){
            maxlen = max(maxlen,right-left+1);
        }
        right++;
    }
    cout<<maxlen;
}