#include<bits/stdc++.h>
using namespace std;

/*
int trappingWater(vector<int> &h){
    int n = h.size();
    vector<int> left(n),right(n);

    // prefix left side ka max
    left[0] = h[0];
    for(int i=1;i<n;i++){
         left[i] = max(left[i-1],h[i]);
    }

    //suffix right side ka max
    right[n-1] = h[n-1];
    for(int i=n-2;i>=0;i--){
         right[i] = max(right[i+1],h[i]);
    }

    int water = 0;
    for(int i=0;i<n;i++){
        water += min(left[i],right[i]) - h[i];
    }
    return water;

}

*/

int trappingWater(vector<int> &h){
    int n = h.size();
    int left = 0 , right = n-1;
    int leftmax = 0 , rightmax = 0;
    int water = 0;

    while(left <= right){
        if(h[left] < h[right]){
            if(h[left] >= leftmax){
                leftmax = h[left];
            } else {
                water += leftmax - h[left];
            }
            left++;
        } else {
            if(h[right] >= rightmax){
                rightmax = h[right];
            } else{
                water += rightmax - h[right];
            }
            right--;
        }
    }
    return water;
}
int main(){
    vector<int> h = {4,2,0,3,2,5};

    cout<<trappingWater(h);
}