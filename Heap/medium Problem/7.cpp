// Hand of Straights

#include<bits/stdc++.h>
using namespace std;

bool isHandOfStraight(vector<int>& hand,int groupSize){
    // pehle sort kr diye
    sort(hand.begin() , hand.end());

    map<int,int> mp;

    // phir sbka freq count kr liye
    for(int i=0;i<hand.size();i++){
        mp[hand[i]]++;
    }

    // har ele pe jao
    for(int i=0;i<hand.size();i++){
        int start = hand[i];

        // already use ho chuka h
        if(mp[start] == 0) continue;

        // consecutive group 
        for(int j=0;j<groupSize;i++){

            int card = start+j;

            if(mp[card] == 0) false;

            mp[card]--;
        }
    }
    return true;
}


int main(){
    vector<int> hand = {1,2,3,6,2,3,4,7,8};

    if(isHandOfStraight(hand,3)){
        cout<<"group found";
    }else{
        cout<<" group not found";
    }
}