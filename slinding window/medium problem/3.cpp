// brute force

/*

#include<bits/stdc++.h>
using namespace std;

int fruitBasket(vector<int>& fruits){
    int maxlen = 0;

    for(int i=0;i<fruits.size();i++){
        unordered_set<int> st;
        for(int j=i;j<fruits.size();j++){
            st.insert(fruits[j]);

            if(st.size() > 2) break;

            maxlen = max(maxlen,j-i+1);
        }
    }
    return maxlen;
}

int main(){
    vector<int> fruits = {3,3,1,1,2};

    cout<<fruitBasket(fruits);
}

*/

// optimal sol

#include<bits/stdc++.h>
using namespace std;

int fruitBasket(vector<int>& fruits){
    unordered_map<int,int> mp;
    int maxlen = 0;
    int left = 0;

    for(int right=0;right<fruits.size();right++){
        mp[fruits[right]]++;

        if(mp.size() > 2){
            mp[fruits[left]]--;

            if(mp[fruits[left]] == 0){
                mp.erase(fruits[left]);
            }
            left++;
        }
        maxlen = max(maxlen,right-left+1);
    }
    return maxlen;
}

int main(){
    vector<int> fruits = {3,3,1,1,2};

    cout<<fruitBasket(fruits);
}