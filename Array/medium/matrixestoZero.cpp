#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    // pehle phla row aur column ko false kr do taki usme check hi na ho
    bool firstRow = false, firstCol = false;

    // pehla row mark
    for(int j = 0;j<m;j++){
        if(matrix[0][j]==0){
            firstRow = true;
            break;
        }
    }

    // pehla column mark 
    for(int i=0;i<n;i++){
        if(matrix[i][0]==0){
            firstCol = true;
            break;
        }
    }

    // ab bich wala me jha jha zero h usko pehla row column me mark kr do
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j]==0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // pehla row aur column mark tha uske entiresara ele ko 0 kr do
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j]=0;
            }
        }
    }

    // ab pehla row check kro khi 0 toh ni usme phir usko 0 kro
    if(firstRow){
        for(int j=0;j<m;j++){
            matrix[0][j] = 0;
        }
    }

    // ab pehla column check kro khi 0 toh ni usme phir usko 0 kro
    if(firstCol){
        for(int i=0;i<n;i++){
            matrix[i][0] = 0;
        }
    }
}

int main(){
    vector<vector<int>> matrix = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    setZeroes(matrix);

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}