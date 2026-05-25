#include<bits/stdc++.h>
using namespace std;

// to find maximum element in array
int findmax(vector<int> &v){
    int maxi = INT_MIN;
    for(int i = 0 ; i<v.size() ; i++){
        maxi = max(maxi,v[i]);
    }
    return maxi;
}

int calculateHour(vector<int> &v,int hourly){
    int totalH = 0;

    for(int i=0;i<v.size();i++){
        totalH += ceil((double) v[i]/(double) hourly); // piles/speed
    }
    return totalH;
}


int minimumRate(vector<int> &v,int h){
    int low = 1;
    int high = findmax(v);

    while(low<=high){
        int mid = (low+high)/2;
        int totalH = calculateHour(v,mid);

        if(totalH <= h){
            high = mid-1;
        }
        else low = mid+1;
    }

}

int main(){
    vector<int> piles = {3,6,7,11};
    int h = 8;
    cout<<minimumRate(piles,h);


}