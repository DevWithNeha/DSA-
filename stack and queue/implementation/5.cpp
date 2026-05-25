#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int key,val,freq;
    node(int k,int v){
        key = k;
        val = v;
        freq = 1;
    }
};

    class LFUCache{
        public:
            int capacity,minFreq;

            unordered_map<int,node*> keynode; // key->node
            unordered_map<int,list<node*>> freqlist;  // freq -> list of nodes;

            LFUCache(int cap){
                capacity = cap;
                minFreq = 0;
            }

        int get(int key){
            if(keynode.find(key) == keynode.end()) return -1;

            node* n = keynode[key];
            int f = n->freq; 

            freqlist[f].remove(n);

            if(f == minFreq && freqlist[f].empty()){
                minFreq++;
            }
            n->freq++;

            freqlist[n->freq].push_front(n);

            return n->val;
        
        }
    void put(int key,int value){
        if(capacity == 0) return;

        // agar value exit karti h pehle se
        if(keynode.find(key) != keynode.end()){
            node* n = keynode[key];
            n->val = value;

            int f = n->freq;

            freqlist[f].remove(n);

            if(f==minFreq && freqlist[f].empty()){
                minFreq++;
            }
            n->freq++;

            freqlist[n->freq].push_front(n);
            return;
        }

        // list ka size full hogya
        if(keynode.size() == capacity){
            node* del = freqlist[minFreq].back();
            freqlist[minFreq].pop_back();
            keynode.erase(del->key);
            delete del;
        }

        // new node add karna ho
        node* n = new node(key,value);
        minFreq = 1;

        freqlist[1].push_front(n);
        keynode[key] = n;
    }
};
    


int main(){
    LFUCache cache(3);

    cache.put(1,10);
    cache.put(2,20);
    cache.put(3,30);
    cache.put(4,40);
    
    cout<<cache.get(3)<<endl;
    cout<<cache.get(2)<<endl;
    cout<<cache.get(4)<<endl;

    cache.put(5,50);

    cout<<cache.get(4)<<endl;

    cache.put(2,25);

}

