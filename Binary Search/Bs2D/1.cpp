#include<bits/stdc++.h>
using namespace std;
int firstone(vector<int>& row , int m){
    int low = 0;
    int high = m-1;
    int ans = -1;

    while(low <= high){
        int mid = (low+high) / 2;

        if(row[mid] == 1){
            ans = mid;
            high = mid-1;
        } else{
            low = mid+1;
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &matrix,int n,int m){
    int maxcount = 0;
    int ansrow = -1;

    for(int i=0;i<n;i++){
        int idx = firstone(matrix[i],m);
    
    int count;
    if(idx == -1){
        count = 0;
    } else{
        count = m-idx;
    }

    if(maxcount < count){
        maxcount = count;
        ansrow = i;
    }
}

return ansrow;
}

int main(){
    vector<vector<int>> matrix = {
        {0,1,1},
        {1,1,1},
        {0,0,0}
    };
    int n = matrix.size();
    int m = matrix[0].size();

    cout<<rowWithMax1s(matrix,n,m);
}