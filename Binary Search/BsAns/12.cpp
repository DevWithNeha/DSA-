#include<bits/stdc++.h>
using namespace std;
bool possible(vector<int> &arr,int k ,double mid){
    int station_needed = 0;

    for(int i=1;i<arr.size();i++){
        int gap = (arr[i]-arr[i-1]);

        station_needed += ceil(gap/mid)-1;
    }
    return station_needed<=k;
}
long double minimiseMaxDistance(vector<int> &arr,int k){
    int n = arr.size();

    double low = 0.0;
    double high = 0.0;

    for(int i=1;i<n;i++){
        high = max(high,double(arr[i]-arr[i-1]));
    }

    double eps = 1e-6;
    while(high-low > eps){

    double mid = (low+high)/2;

    if(possible(arr,k,mid)){
        high = mid;
    } else{
        low = mid;
    }
    }
    return high;
}

int main(){
    vector<int> arr = {1,2,3,4,10};
    int k = 2;

    cout<<minimiseMaxDistance(arr,k);
}