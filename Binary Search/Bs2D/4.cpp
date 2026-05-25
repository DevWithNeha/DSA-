#include<bits/stdc++.h>
using namespace std;
int findMaxEle(vector<vector<int>>& mat,int n,int col){
    int maxvalue = mat[0][col];
    int index = 0;

    for(int i=1;i<n;i++){
        if(mat[i][col] > maxvalue){
            maxvalue= mat[i][col];
            index = i;
        }
    }
    return index;
}

vector<int> findPeakGrid(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    int low = 0;
    int high = m-1;

    while(low<=high){
        int mid = (low+high)/2;

        int maxrow = findMaxEle(mat,n,mid);
        
        // left ke liye
        if(mid > 0 && mat[maxrow][mid-1] > mat[maxrow][mid]){
            high = mid-1;
        }else if(mid < m-1 && mat[maxrow][mid+1] > mat[maxrow][mid]){
            low = mid+1;
        } else{
            return {maxrow,mid};
        }
    }
    return {-1,-1};
}

int main(){
    vector<vector<int>> mat = {
        {10,20,15},
        {21,30,14},
        {7,16,32}
    };
    
    vector<int> ans = findPeakGrid(mat); 

    cout<<ans[0]<<","<<ans[1]<<endl;


}