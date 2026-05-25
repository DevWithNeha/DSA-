#include<bits/stdc++.h>
using namespace std;

// bool searchMatrix(vector<vector<int>>& matrix,int target){
//     int n = matrix.size();
//     int m = matrix[0].size();

//     for(int i=0;i<n;i++){
//         if(target >= matrix[i][0] && target <= matrix[i][m-1]){
//             int low = 0;
//             int high = m-1;
            
//             while(low<=high){
//                 int mid = (low+high)/2;
//                     if(matrix[i][mid] == target) return true;
//                     else if(matrix[i][mid] < target) low = mid+1;
//                     else high = mid-1;
//             }
//         }
//     }
//     return false;
// }

bool searchMatrix(vector<vector<int>>& matrix,int target){
    int n = matrix.size();
    int m = matrix[0].size();

    int i = 0;
    int j = m-1;

    while(i < n && j >= 0){
        if(matrix[i][j] == target) return true;
        else if(matrix[i][j] < target) i++;
        else j--;
    }
    return false;
}

int main(){
    vector<vector<int>> matrix = {
        {1,4,7,11},
        {2,5,8,12},
        {3,6,9,16},
        {10,13,14,17}
    };

    int target = 6;

    int ans = searchMatrix(matrix,target);

    if(ans){
        cout<<"found";
    }else{
        cout<<"not found";
    }
}