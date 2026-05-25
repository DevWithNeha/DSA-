#include<bits/stdc++.h>
using namespace std;
string minWindow(string s1,string s2){
    int n = s1.size(),m = s2.size();
    int minlen = INT_MAX;
    int startindex = -1;

    for(int i=0;i<n;i++){
        if(s1[i] == s2[0]){
            int j = i;
            int k = 0;
            
            // forward dekhenge

            while(j<n && k<m){
                if(s1[j] == s2[k]){
                    k++;
                }
                j++;
            }

            // agar pura t match hogya
            if(k == m){
                int end = j-1;
                int k = m-1;
                int j = end;

                while(j >= i){
                    if(s1[j] == s2[k]){
                        k--;
                        if(k < 0) break;
                    }
                    j--;
                }
                    int start = j;

                    if(end - start + 1 < minlen){
                        minlen = end - start + 1;
                        startindex = j;
                    }
               }
        }
    }
    if(startindex == -1) return " ";
    return s1.substr(startindex,minlen);
}

int main(){
    string s1 = "abcdebdde";
    string s2 = "bde";

    cout<<minWindow(s1,s2);
}