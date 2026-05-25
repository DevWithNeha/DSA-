// brute force

/*
#include<bits/stdc++.h>
using namespace std;
int maxCard(vector<int>& arr,int k){
    int n = arr.size();
    int maxsum = 0;

    for(int i=0;i<=k;i++){
        int sum = 0;
        // left part
        for(int j=0;j<i;j++){
            sum += arr[j];
        }

        // right part

        for(int j=n-(k-i);j<n;j++){
            sum += arr[j];
        }
        maxsum = max(maxsum,sum);
    }
    return maxsum;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    int k = 3;

    cout<<maxCard(arr,k);
}

*/

// optimal solution

#include<bits/stdc++.h>
using namespace std;
int maxCard(vector<int>& arr,int k){
    int n = arr.size();
    int totalsum = 0;
    int windowsize = n-k;

    for(int x:arr){
        totalsum += x;
    }

    int currsum = 0;
    for(int i=0;i<windowsize;i++){
        currsum += arr[i];
    }

    int minsum = currsum;

    //window slide krke sbka sum nikalenge

    for(int i=windowsize;i<n;i++){
        currsum += arr[i];
        currsum -= arr[i - windowsize];

        minsum = min(minsum,currsum);
    }
    return totalsum-minsum;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6};
    int k = 3;

    cout<<maxCard(arr,k);
}