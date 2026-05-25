#include<bits/stdc++.h>
using namespace std;
int longestrepeatingchar(string s,int k){
    vector<int> freq(26,0);
    int left = 0,maxfreq = 0,maxlen = 0;

    for(int right=0;right<s.size();right++){
        freq[s[right] - 'A']++;

        maxfreq = max(maxfreq,freq[s[right] - 'A']);

        if(right-left+1 - maxfreq > k){
            freq[s[left] - 'A']--;
            left++;
        }
        maxlen = max(maxlen,right-left+1);
    }
    return maxlen;
}

int main(){
    string s;
    cout<<"enter string: ";
    cin>>s;

    int k;
    cout<<"enter k:";
    cin>>k;

    cout<<longestrepeatingchar(s,k);
}