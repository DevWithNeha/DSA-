#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &arr){
    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;

    for(int i=0;i<arr.size();i++){
        if(ans.empty() || arr[i][0]>ans.back()[1]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1] = max(arr[i][1],ans.back()[1]);
        }
        
    }
    return ans;
}

int main(){
    
    vector<vector<int>> arr = {
        {1,3},{2,6},{8,10},{15,18}
    };

    vector<vector<int>> result = merge(arr);

    for(auto v:result){
        cout<<"["<<v[0]<<","<<v[1]<<"]";
    }

}