#include<bits/stdc++.h>
using namespace std;
bool search2D(vector<vector<int>> &matrix , int target){
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0;
    int high = n*m -1;

    while(low<=high){
        int mid = (low+high)/2;

        int row = mid/m;
        int col = mid%m;

        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] < target) low = mid+1;
        else high = mid-1;
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {
        {1,2,4},
        {5,6,7},
        {10,11,12}
    };

    int target = 7;

    int res = search2D(matrix,target);

    if(res){
        cout<<"element found";
    } else{
        cout<<"not found";
    }
}