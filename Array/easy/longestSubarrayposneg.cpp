#include<bits/stdc++.h>
using namespace std;
int longestsubArrayposAndneg(vector<int> &arr,int k){
    map<int,int> mp;

    int n = arr.size();
    int prefixsum = 0;
    int maxlen = 0;

    for(int i=0;i<n;i++){
        prefixsum += arr[i];
    
        //starting se i tak ka index check kro
    if(prefixsum == k){
        maxlen = i+1;
    }

    // agar prefix - k pehle milta h toh wha ke inddex se oldindex ko minus krke uska maxlen store kr do
    if(mp.find(prefixsum-k)!=mp.end()){
        maxlen = max(maxlen,i-mp[prefixsum-k]);
    }

    // agar prefix -k ni milta h toh usko map me store kr doo
    if(mp.find(prefixsum-k)==mp.end()){
        mp[prefixsum]=i;
    }
    }
    return maxlen;
}
int main(){
    vector<int> arr = {10,5,2,7,1,9};
    int k = 15;

    cout<<longestsubArrayposAndneg(arr,k);
}